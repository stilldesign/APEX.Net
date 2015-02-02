#include "StdAfx.h"
#include "Interface.h"
#include "ApexSdk.h"

Interface::Interface(NxParameterized::Interface* i, ApexSdk^ owner)
{
	if (i == NULL)
		throw gcnew ArgumentNullException("i");
	ThrowIfNullOrDisposed(owner, "owner");

	_interface = i;

	ObjectTable::Add((intptr_t)i, this, owner);
}
Interface::~Interface()
{
	this->!Interface();
}
Interface::!Interface()
{
	_interface->destroy();
	_interface = NULL;
}
bool Interface::Disposed::get()
{
	return _interface == NULL;
}

void Interface::InitalizeToDefaults()
{
	_interface->initDefaults();
}

array<int>^ Interface::Checksum(int bits)
{
	PxU32 b = (PxU32)bits;
	const PxU32* checksum = _interface->checksum(b);

	return Util::AsManagedArray<int>(checksum, bits);
}

//

String^ Interface::ClassName::get()
{
	return Util::ToManagedString(_interface->className());
}
void Interface::ClassName::set(String^ value)
{
	_interface->setClassName(Util::ToUnmanagedString(value));
}

String^ Interface::Name::get()
{
	return Util::ToManagedString(_interface->name());
}
void Interface::Name::set(String^ value)
{
	_interface->setName(Util::ToUnmanagedString(value));
}

int Interface::Version::get()
{
	return _interface->version();
}

int Interface::NumberOfParameters::get()
{
	return _interface->numParameters();
}

NxParameterized::Interface* Interface::UnmanagedPointer::get()
{
	return _interface;
}