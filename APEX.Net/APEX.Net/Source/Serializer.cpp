#include "StdAfx.h"
#include "Serializer.h"
#include "ApexSdk.h"
#include "InMemoryFileBuf.h"
#include "Interface.h"

Serializer::Serializer(NxParameterized::Serializer* serializer, ApexSdk^ owner)
{
	_serializer = serializer;
	_owner = owner;

	ObjectTable::Add((intptr_t)serializer, this, owner);
}
Serializer::~Serializer()
{
	this->!Serializer();
}
Serializer::!Serializer()
{
	OnDisposing(this, nullptr);

	if (Disposed)
		return;

	_serializer->release();
	_serializer = NULL;

	_owner = nullptr;

	OnDisposed(this, nullptr);
}

bool Serializer::Disposed::get()
{
	return _serializer == NULL;
}

array<Interface^>^ Serializer::Deserialize(System::IO::Stream^ serializedDataStream)
{
	ThrowIfNull(serializedDataStream, "serializedDataStream");

	InMemoryFileBuf nativeStream(serializedDataStream->Length);
	const int ReadSize = 4096;
	auto b = gcnew array<Byte>(ReadSize);
	while (serializedDataStream->Position < serializedDataStream->Length)
	{
		int r = System::Math::Min(ReadSize, (int)(serializedDataStream->Length - serializedDataStream->Position));

		serializedDataStream->Read(b, 0, r);

		pin_ptr<Byte> b_pin = &b[0];
		nativeStream.write(b_pin, r);
	}

	if (nativeStream.getFileLength() != serializedDataStream->Length) throw gcnew Exception();
	if (nativeStream.tellRead() != serializedDataStream->Length) throw gcnew Exception();
	if (nativeStream.tellWrite() != serializedDataStream->Length) throw gcnew Exception();

	nativeStream.seekRead(0);
	nativeStream.seekWrite(0);

	NxParameterized::Serializer::DeserializedData r;

	auto error = _serializer->deserialize(nativeStream, r);

	if (error != NxParameterized::Serializer::ErrorType::ERROR_NONE)
		throw gcnew OperationFailedException("Failed to deserialize stream. Error: '{0}'", ToManagedEnum(SerializationError, error));

	int n = r.size();

	auto interfaces = gcnew array<Interface^>(n);

	for (int i = 0; i < n; i++)
	{
		interfaces[i] = gcnew Interface(r[i], _owner);
	}

	return interfaces;
}

NxParameterized::Serializer* Serializer::UnmanagedPointer::get()
{
	return _serializer;
}