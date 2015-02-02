#include "StdAfx.h"

//void* GetNative(Object^ obj)
//{
//	Type^ t = obj->GetType();
//	auto p = t->GetProperty("UnmanagedPointer", System::Reflection::BindingFlags::NonPublic | System::Reflection::BindingFlags::Static);
//
//	System::Reflection::Pointer^ native = (System::Reflection::Pointer^)p->GetValue(obj, nullptr);
//
//	return System::Reflection::Pointer::Unbox(native);
//}