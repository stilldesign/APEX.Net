#pragma once

#include "module\destructible\public\NxDestructibleActor.h"

namespace PhysX
{
	namespace Apex
	{
		public value struct DestructibleHitChunk
		{
		internal:
			static NxDestructibleHitChunk ToUnmanaged(DestructibleHitChunk managed);
			static DestructibleHitChunk ToManaged(NxDestructibleHitChunk unmanaged);

		public:
			property int ChunkIndex;
			property int HitChunkFlags;
		};
	}
}