#include "StdAfx.h"
#include "RenderDebug.h"
#include "ApexSdk.h"

RenderDebug::RenderDebug(NxApexRenderDebug* debug, ApexSdk^ owner)
{
	if (debug == NULL)
		throw gcnew ArgumentNullException("debug");
	ThrowIfNullOrDisposed(owner, "owner");

	_debug = debug;
	_owner = owner;

	ObjectTable::Add((intptr_t)debug, this, owner);
}
RenderDebug::~RenderDebug()
{
	this->!RenderDebug();
}
RenderDebug::!RenderDebug()
{
	OnDisposing(this, nullptr);

	if (Disposed)
		return;

	_owner->UnmanagedPointer->releaseApexRenderDebug(*_debug);
	_debug = NULL;
	_owner = nullptr;

	OnDisposed(this, nullptr);
}

bool RenderDebug::Disposed::get()
{
	return _debug == NULL;
}

//PhysX::DebugRenderable^ RenderDebug::GetDebugRenderable()
//{
//	//PhysX::DebugRenderable^ dr = gcnew PhysX::DebugRenderable();
//
//	throw gcnew NotImplementedException();
//}