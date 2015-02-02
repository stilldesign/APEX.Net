#include "StdAfx.h"
#include "ApexActor.h"
#include "ApexSdk.h"
#include "Interface.h"
#include "ApexScene.h"
#include "ApexActorGetPhysicalLodRange.h"
#include "Asset.h"

ApexActor::ApexActor(NxApexActor* apexActor, Asset^ owner)
{
	ThrowIfNull(apexActor, "apexActor");
	ThrowIfNullOrDisposed(owner, "owner");

	_apexActor = apexActor;

	ObjectTable::Add((intptr_t)apexActor, this, owner);
}
ApexActor::~ApexActor()
{
	this->!ApexActor();
}
ApexActor::!ApexActor()
{
	if (this->Disposed)
		return;

	OnDisposing(this, nullptr);

	_apexActor->release();
	_apexActor = NULL;

	OnDisposed(this, nullptr);
}

bool ApexActor::Disposed::get()
{
	return _apexActor == NULL;
}

Asset^ ApexActor::Owner::get()
{
	return ObjectTable::GetObject<Asset^>((intptr_t)_apexActor->getOwner());
}

ApexActorGetPhysicalLodRange^ ApexActor::PhysicalLodRange::get()
{
	PxF32 min, max;
	bool intOnly;

	_apexActor->getPhysicalLodRange(min, max, intOnly);

	auto lodRange = gcnew ApexActorGetPhysicalLodRange();

	lodRange->Min = min;
	lodRange->Max = max;
	lodRange->IntegerOnly = intOnly;

	return lodRange;
}

float ApexActor::ActivePhysicalLod::get()
{
	return _apexActor->getActivePhysicalLod();
}

void ApexActor::ForcePhysicalLod(float lod)
{
	_apexActor->forcePhysicalLod(lod);
}

void ApexActor::CacheModuleData()
{
	_apexActor->cacheModuleData();
}

void ApexActor::SetEnableDebugVisualization(bool state)
{
	_apexActor->setEnableDebugVisualization(state);
}

NxApexActor* ApexActor::UnmanagedPointer::get()
{
	return _apexActor;
}