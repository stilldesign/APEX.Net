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
				public ref class DestructibleParameters
				{
				internal:
					static DestructibleParameters^ ToManaged(NxDestructibleParameters unmanaged);
					static NxDestructibleParameters ToUnmanaged(DestructibleParameters^ managed);

				public:
					property float DamageCap;
					property float ForceToDamage;
					property float ImpactVelocityThreshold;
					property int MinimumFractureDepth;
					property int ImpactDamageDefaultDepth;
					property int DebrisDepth;
					property int EssentialDepth;
					property float DebrisLifetimeMin;
					property float DebrisLifetimeMax;
					property float DebrisMaxSeparationMin;
					property float DebrisMaxSeparationMax;
					property float DebrisDestructionProbability;
					property Bounds3 ValidBounds;
					property float MaxChunkSpeed;
					property int Flags;
					property float FractureImpulseScale;
					property int DamageDepthLimit;
					property Byte DynamicChunksDominanceGroup;
					property bool UseDynamicChunksGroupsMask;
					property int DepthParametersCount;
					//property NxDestructibleDepthParameters depthParameters[kDepthParametersCountMax];
					//property NxDestructibleRTFractureParameters rtFractureParameters;
				};
			}
		}
	}
}