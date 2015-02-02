#pragma once

#include "foundation/PxErrorCallback.h"

class UserErrorCallback : public physx::PxErrorCallback
{
	virtual void reportError(PxErrorCode::Enum code, const char* message, const char* file, int line)
	{
		int q = 2;
	}
};