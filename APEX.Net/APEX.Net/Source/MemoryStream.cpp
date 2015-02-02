#include "StdAfx.h"
#include "MemoryStream.h"

//MemoryStream::MemoryStream()
//{
//	_capacity = 0;
//	_memory = _seek = new const NxU8[0];
//
//	assert(_memory != NULL);
//}
//MemoryStream::MemoryStream(const NxU8* memory, int size)
//{
//	assert(_memory != NULL);
//	assert(size >= 0);
//
//	_capacity = sizeof(NxU8) * size;
//	_memory = _seek = memory;
//}
//MemoryStream::MemoryStream(long byteSize)
//{
//	assert(byteSize >= 0);
//
//	_capacity = sizeof(NxU8) * byteSize;
//	_memory = _seek = new const NxU8[_capacity];
//
//	assert(_memory != NULL);
//}
//MemoryStream::~MemoryStream()
//{
//	if (_memory)
//		delete[] _memory;
//
//	_memory = _seek = NULL;
//	_capacity = 0;
//}
//
//NxU8 MemoryStream::readByte() const
//{
//	NxU8 b;
//	memcpy(&b, _seek, sizeof(NxU8));
//	_seek += sizeof(NxU8);
//	return b;
//}
//NxU16 MemoryStream::readWord() const
//{
//	NxU16 w;
//	memcpy(&w, _seek, sizeof(NxU16));
//	_seek += sizeof(NxU16);
//	return w;
//}
//NxU32 MemoryStream::readDword() const
//{
//	NxU32 d;
//	memcpy(&d, _seek, sizeof(NxU32));
//	_seek += sizeof(NxU32);
//	return d;
//}
//NxF32 MemoryStream::readFloat() const
//{
//	float f;
//	memcpy(&f, _seek, sizeof(float));
//	_seek += sizeof(float);
//	return f;
//}
//NxF64 MemoryStream::readDouble() const
//{
//	double f;
//	memcpy(&f, _seek, sizeof(double));
//	_seek += sizeof(double);
//	return f;
//}
//void MemoryStream::readBuffer(void* buffer, NxU32 size) const
//{
//	memcpy(buffer, _seek, size);
//	_seek += size;
//}
//
//NxStream& MemoryStream::storeByte(NxU8 b)
//{
//	return storeBuffer(&b, sizeof(NxU8));
//}
//NxStream& MemoryStream::storeWord(NxU16 w)
//{
//	return storeBuffer(&w, sizeof(NxU16));
//}
//NxStream& MemoryStream::storeDword(NxU32 d)
//{
//	return storeBuffer(&d, sizeof(NxU32));
//}
//NxStream& MemoryStream::storeFloat(NxF32 f)
//{
//	return storeBuffer(&f, sizeof(NxF32));
//}
//NxStream& MemoryStream::storeDouble(NxF64 f)
//{
//	return storeBuffer(&f, sizeof(NxF64));
//}
//NxStream& MemoryStream::storeBuffer(const void* buffer, NxU32 size)
//{
//	size_t usedSize = getMemorySize();
//
//	size_t expectedSize = usedSize + size;
//	if(expectedSize > _capacity)
//	{
//		_capacity = expectedSize + 4096;
//
//		NxU8* newData = new NxU8[_capacity];
//		NX_ASSERT(newData!=NULL);
//
//		if (_memory)
//		{
//			memcpy(newData, _memory, usedSize);
//			delete[] _memory;
//		}
//		_memory = newData;
//		_seek = newData + usedSize;
//	}
//	memcpy((void*)_seek, buffer, size);
//	_seek += size;
//	return *this;
//}