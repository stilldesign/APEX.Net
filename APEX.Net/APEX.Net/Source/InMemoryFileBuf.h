#pragma once

namespace PhysX
{
	namespace Apex
	{
		class InMemoryFileBuf : public physx::general_PxIOStream2::PxFileBuf
		{
		private:
			BYTE* _data;
			unsigned int _length;
			unsigned int _seek;

		public:
			InMemoryFileBuf(unsigned int length)
			{
				_data = new BYTE[length];
				_length = length;
				_seek = 0;
			}

			virtual OpenMode	getOpenMode(void) const
			{
				return OpenMode::OPEN_READ_WRITE_EXISTING;
			}

			virtual SeekType isSeekable(void) const
			{
				return SeekType::SEEKABLE_READWRITE;
			}

			virtual PxU32 getFileLength(void) const
			{
				return _length;
			}

			/**
			\brief Seeks the stream to a particular location for reading
			*
			* If the location passed exceeds the length of the stream, then it will seek to the end.
			* Returns the location it ended up at (useful if you seek to the end) to get the file position
			*/
			virtual PxU32	seekRead(PxU32 loc)
			{
				if (loc > _length)
					loc = _length;
				else if (loc < 0)
					loc = 0;

				_seek = loc;

				return _seek;
			}

			/**
			\brief Seeks the stream to a particular location for writing
			*
			* If the location passed exceeds the length of the stream, then it will seek to the end.
			* Returns the location it ended up at (useful if you seek to the end) to get the file position
			*/
			virtual PxU32	seekWrite(PxU32 loc)
			{
				if (loc > _length)
					loc = _length;
				else if (loc < 0)
					loc = 0;

				_seek = loc;

				return _seek;
			}

			/**
			\brief Reads from the stream into a buffer.

			\param[out] mem  The buffer to read the stream into.
			\param[in]  len  The number of bytes to stream into the buffer

			\return Returns the actual number of bytes read.  If not equal to the length requested, then reached end of stream.
			*/
			virtual PxU32	read(void *mem, PxU32 len)
			{
				if (_seek + len > _length)
					len = _length - _seek;

				memcpy(mem, _data + _seek, len);

				_seek += len;

				return len;
			}


			/**
			\brief Reads from the stream into a buffer but does not advance the read location.

			\param[out] mem  The buffer to read the stream into.
			\param[in]  len  The number of bytes to stream into the buffer

			\return Returns the actual number of bytes read.  If not equal to the length requested, then reached end of stream.
			*/
			virtual PxU32	peek(void *mem, PxU32 len)
			{
				if (_seek + len > _length)
					len = _length - _seek;

				memcpy(mem, _data + _seek, len);

				return len;
			}

			/**
			\brief Writes a buffer of memory to the stream

			\param[in] mem The address of a buffer of memory to send to the stream.
			\param[in] len  The number of bytes to send to the stream.

			\return Returns the actual number of bytes sent to the stream.  If not equal to the length specific, then the stream is full or unable to write for some reason.
			*/
			virtual PxU32	write(const void *mem, PxU32 len)
			{
				if (_seek + len > _length)
					len = _length - _seek;

				memcpy(_data + _seek, mem, len);

				_seek += len;

				return len;
			}

			/**
			\brief Reports the current stream location read aqccess.

			\return Returns the current stream read location.
			*/
			virtual PxU32	tellRead(void) const
			{
				return _seek;
			}

			/**
			\brief Reports the current stream location for write access.

			\return Returns the current stream write location.
			*/
			virtual PxU32	tellWrite(void) const
			{
				return _seek;
			}

			/**
			\brief	Causes any temporarily cached data to be flushed to the stream.
			*/
			virtual	void	flush(void)
			{

			}
		};
	}
}