#include "StdAfx.h"
#include "DestructibleChunkDesc.h"

using namespace PhysX::Apex::Modules::Destructible;

NxDestructibleChunkDesc DestructibleChunkDesc::ToUnmanaged(DestructibleChunkDesc^ managed)
{
	NxDestructibleChunkDesc unmanaged;

	unmanaged.isSupportChunk = managed->IsSupportChunk;
	unmanaged.doNotFracture = managed->DoNotFracture;
	unmanaged.doNotDamage = managed->DoNotDamage;
	unmanaged.doNotCrumble = managed->DoNotCrumble;
	unmanaged.useInstancedRendering = managed->UseInstancedRendering;
	unmanaged.instancePositionOffset = UV(managed->InstancePositionOffset);
	unmanaged.instanceUVOffset = MathUtil::Vector2ToPxVec2(managed->InstanceUVOffset);
	unmanaged.meshIndex = managed->MeshIndex;
	unmanaged.parentIndex = managed->ParentIndex;
	unmanaged.surfaceNormal = UV(managed->SurfaceNormal);
	unmanaged.behaviorGroupIndex = managed->BehaviorGroupIndex;

	unmanaged.scatterMeshCount = managed->ScatterMeshCount;
	if (managed->ScatterMeshCount > 0)
	{
		unmanaged.scatterMeshIndices = (PxU8*)malloc(managed->ScatterMeshCount * sizeof(PxU8));
		Util::AsUnmanagedArray(managed->ScatterMeshIndices, (void*)unmanaged.scatterMeshIndices);

		unmanaged.scatterMeshTransforms = (PxMat44*)malloc(managed->ScatterMeshCount * sizeof(PxMat44));
		Util::AsUnmanagedArray(managed->ScatterMeshTransforms, (void*)unmanaged.scatterMeshTransforms);
	}

	return unmanaged;
}