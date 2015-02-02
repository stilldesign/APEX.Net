#pragma once

#include "foundation/PxAllocatorCallback.h"

class UserAllocatorCallback : public physx::PxAllocatorCallback
{
	virtual void* allocate(size_t size, const char* typeName, const char* filename, int line)
	{
		return malloc(size);
	}

	virtual void deallocate(void* ptr)
	{
		deallocate(ptr);
	}
};