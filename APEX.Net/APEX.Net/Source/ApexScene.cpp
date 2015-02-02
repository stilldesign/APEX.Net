#include "StdAfx.h"
#include "ApexScene.h"
#include "ApexSdk.h"

ApexScene::ApexScene(NxApexScene* scene, ApexSdk^ apexSdk)
{
	ThrowIfNull(scene, "scene");
	ThrowIfNullOrDisposed(apexSdk, "apexSdk");

	_apexScene = scene;
	_SDK = apexSdk->UnmanagedPointer;

	ObjectTable::Add((intptr_t)scene, this, apexSdk);
}
ApexScene::~ApexScene()
{
	this->!ApexScene();
}
ApexScene::!ApexScene()
{
	if (Disposed)
		return;

	OnDisposing(this, EventArgs::Empty);

	_SDK->releaseScene(_apexScene);
	_apexScene = NULL;
	_SDK = NULL;

	OnDisposed(this, EventArgs::Empty);
}

bool ApexScene::Disposed::get()
{
	return _apexScene == NULL;
}



//

NxApexScene* ApexScene::UnmanagedPointer::get()
{
	return _apexScene;
}