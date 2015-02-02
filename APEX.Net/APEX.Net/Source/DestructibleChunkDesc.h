#pragma once

#include <NxDestructibleAsset.h>

namespace PhysX
{
namespace Apex
{
namespace Modules
{
	namespace Destructible
	{
		public ref class DestructibleChunkDesc
		{
		internal:
			static NxDestructibleChunkDesc ToUnmanaged(DestructibleChunkDesc^ managed);

		public:
			property bool IsSupportChunk;
			property bool DoNotFracture;
			property bool DoNotDamage;
			property bool DoNotCrumble;
			property bool UseInstancedRendering;
			property Vector3 InstancePositionOffset;
			property Vector2 InstanceUVOffset;
			property int MeshIndex;
			property int ParentIndex;
			property Vector3 SurfaceNormal;
			property int BehaviorGroupIndex;
			property int ScatterMeshCount;
			property array<int>^ ScatterMeshIndices;
			property array<Matrix>^ ScatterMeshTransforms;

		};
	};
};
};
};