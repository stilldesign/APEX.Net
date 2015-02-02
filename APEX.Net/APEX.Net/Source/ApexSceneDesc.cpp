#include "StdAfx.h"
#include "ApexSceneDesc.h"

NxApexSceneDesc ApexSceneDesc::ToUnmanaged(ApexSceneDesc^ managed)
{
	NxApexSceneDesc unmanaged;

	unmanaged.useDebugRenderable = managed->UseDebugRenderable;
	unmanaged.debugVisualizeRemotely = managed->DebugVisualizeRemotely;
	unmanaged.debugVisualizeLocally = managed->DebugVisualizeLocally;
	//unmanaged.

	return unmanaged;
}