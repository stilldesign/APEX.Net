#pragma once

//#include <NxStream.h>
//
//class MemoryStream : public NxStream
//{
//	private:
//		const NxU8* _memory;
//		mutable const NxU8* _seek;
//		size_t _capacity;
//
//	public:
//		MemoryStream();
//		MemoryStream(const NxU8* memory, int size);
//		MemoryStream(long byteSize);
//		virtual ~MemoryStream();
//
//		virtual NxU8 readByte() const;
//		virtual NxU16 readWord() const;
//		virtual NxU32 readDword() const;
//		virtual NxF32 readFloat() const;
//		virtual NxF64 readDouble() const;
//		virtual void readBuffer(void* buffer, NxU32 size) const;
//		    
//		virtual NxStream& storeByte(NxU8 b);
//		virtual NxStream& storeWord(NxU16 w);
//		virtual NxStream& storeDword(NxU32 d);
//		virtual NxStream& storeFloat(NxF32 f);
//		virtual NxStream& storeDouble(NxF64 f);
//		virtual NxStream& storeBuffer(const void* buffer, NxU32 size);
//
//		const NxU8* GetMemory()
//		{
//			return _memory;
//		}
//		size_t getMemorySize()
//		{
//			size_t size = _seek - _memory;
//			assert(size >= 0);
//			
//			return size;
//		}
//
//		void ResetSeek()
//		{
//			_seek = _memory;
//		}
//};
//
//typedef MemoryStream InternalMemoryStream;