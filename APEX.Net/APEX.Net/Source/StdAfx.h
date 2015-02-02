#pragma once

#define WIN32_LEAN_AND_MEAN

// We need to include the PhysX.Net DLL this way instead of 'Add Reference' as we need to use the
// special keyword 'as_friend' in order to get access to its internal properties (e.g. UnmanagedPointer)
// Search path for DLLs is specified in the project properties under C/C++ > General > 'Additional #using Directories'
#using <PhysX.Net-3.3.1\PhysX.Net.dll> as_friend

#include <Windows.h>
#include <vcclr.h>
#include <memory.h>
#include <assert.h>
#include <vector>

#include <NxApex.h>

// .NET namespaces
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Linq;
using namespace System::Diagnostics;
using namespace System::Runtime::InteropServices;

#include "ApexException.h"
#include "Util.h"

// Our namespaces
using namespace PhysX::Apex;
using namespace PhysX::Math;

// Native PhysX namespaces
using namespace physx;
using namespace physx::apex;
//using namespace  physx::pubfnd2;

// Enum conversion
#define ToManagedEnum(managedType, e) ((managedType)(PxU32)e)
#define ToUnmanagedEnum(unmanagedType, e) ((unmanagedType::Enum)(PxU32)e)
#define ToUnmanagedEnum2(unmanagedType, e) ((unmanagedType)(PxU32)e)

#define SAFE_DELETE(p) { if((p) != NULL){ delete (p); (p) = NULL; } }
#define SAFE_FREE(p) { if((p) != NULL){ free(p); (p) = NULL; } }

#define GetPointerOrNull(obj) (obj == nullptr ? NULL : obj->UnmanagedPointer)

#define MV(v) (MathUtil::PxVec3ToVector3(&v))
#define UV(v) (MathUtil::Vector3ToPxVec3(v))
#define MM(m) (MathUtil::PxTransformToMatrix(&m))
#define UM(m) (MathUtil::MatrixToPxTransform(m))

#define ThrowIfNull( var, varName )\
{\
	if (var == nullptr)\
		throw gcnew ArgumentNullException(varName);\
}
#define ThrowIfNullOrDisposed(var, varName)\
{\
	if (var == nullptr)\
		throw gcnew ArgumentNullException(varName);\
	if (var->Disposed)\
		throw gcnew ArgumentException("Argument is disposed", varName);\
}
#define ThrowIfDisposed(var, varName)\
{\
	if (var != nullptr && var->IsDisposed)\
		throw gcnew ArgumentException("Argument is disposed", varName);\
}
#define ThrowIfDescriptionIsNullOrInvalid(var, varName)\
{\
	ThrowIfNull(var, varName);\
	\
	if(!var->IsValid())\
		throw gcnew ArgumentException("Description is invalid", varName);\
}

template <class T, class U>
bool IsInstanceOf(U u)
{
	return dynamic_cast<T>(u) != nullptr;
}