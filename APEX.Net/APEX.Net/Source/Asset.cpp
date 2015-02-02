#include "StdAfx.h"
#include "Asset.h"
#include "ApexSdk.h"
#include "Interface.h"
#include "ApexScene.h"
#include "ApexActor.h"

Asset::Asset(NxApexAsset* asset, ApexSdk^ owner)
{
	ThrowIfNull(asset, "asset");
	ThrowIfNullOrDisposed(owner, "owner");

	_asset = asset;
	_apexSdk = owner;

	ObjectTable::Add((intptr_t)asset, this, owner);
}
Asset::~Asset()
{
	this->!Asset();
}
Asset::!Asset()
{
	if (this->Disposed)
		return;

	OnDisposing(this, nullptr);

	_asset->release();
	_asset = NULL;

	OnDisposed(this, nullptr);
}

bool Asset::Disposed::get()
{
	return _asset == NULL;
}

bool Asset::IsValidForCreation(Interface^ actorParameters, ApexScene^ scene)
{
	ThrowIfNullOrDisposed(actorParameters, "actorParameters");
	ThrowIfNullOrDisposed(scene, "scene");

	return _asset->isValidForActorCreation(*actorParameters->UnmanagedPointer, *scene->UnmanagedPointer);
}

Interface^ Asset::GetDefaultActorDesc()
{
	auto i = _asset->getDefaultActorDesc();

	return gcnew Interface(i, _apexSdk);
}

ApexActor^ Asset::CreateApexActor(Interface^ actorParameters, ApexScene^ apexScene)
{
	ThrowIfNullOrDisposed(actorParameters, "actorParameters");
	ThrowIfNullOrDisposed(apexScene, "apexScene");

	NxApexActor* a = _asset->createApexActor(*actorParameters->UnmanagedPointer, *apexScene->UnmanagedPointer);

	return gcnew ApexActor(a, this);
}

String^ Asset::Name::get()
{
	return Util::ToManagedString(_asset->getName());
}

int Asset::ObjectTypeId::get()
{
	return _asset->getObjTypeID();
}

String^ Asset::ObjectTypeName::get()
{
	return Util::ToManagedString(_asset->getObjTypeName());
}

bool Asset::IsDirty::get()
{
	return _asset->isDirty();
}

NxApexAsset* Asset::UnmanagedPointer::get()
{
	return _asset;
}