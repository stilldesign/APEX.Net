#pragma once

#include <module\destructible\public\NxDestructibleAsset.h>
#include <module\destructible\public\NxDestructibleActor.h>

#pragma once

namespace PhysX
{
	namespace Apex
	{
		namespace Modules
		{
			namespace Destructible
			{
				public enum class DestructibleParametersFlag
				{
					/// <summary>
					/// If set, chunks will "remember" damage applied to them, so that many applications of a damage amount below 
					/// damageThreshold will eventually fracture the chunk.  If not set, a single application of damage must exceed 
					/// damageThreshold in order to fracture the chunk.
					/// </summary>
					AccumulateDamage = NxDestructibleParametersFlag::ACCUMULATE_DAMAGE,

					/// <summary>
					/// Whether or not chunks at or deeper than the "debris" depth (see DestructibleParameters::debrisDepth) will time out.  
					/// The lifetime is a value between DestructibleParameters::debrisLifetimeMin and 
					/// DestructibleParameters::debrisLifetimeMax, based upon the destructible module's LOD setting.
					/// </summary>
					DebrisTimeout = NxDestructibleParametersFlag::DEBRIS_TIMEOUT,

					/// <summary>
					/// Whether or not chunks at or deeper than the "debris" depth (see DestructibleParameters::debrisDepth) will be removed if 
					/// they separate too far from their origins.  The maxSeparation is a value between 
					/// DestructibleParameters::debrisMaxSeparationMin and DestructibleParameters::debrisMaxSeparationMax, based upon the 
					/// destructible module's LOD setting.
					/// </summary>
					DebrisMaxSeparation = NxDestructibleParametersFlag::DEBRIS_MAX_SEPARATION,

					/// <summary>
					/// If set, the smallest chunks may be further broken down, either by fluid crumbles (if a crumble particle system is 
					/// specified in the DestructibleActorDesc), or by simply removing the chunk if no crumble particle system is specified.  
					/// Note: the "smallest chunks" are normally defined to be the deepest level of the fracture hierarchy.  However, they may 
					/// be taken from higher levels of the hierarchy if ModuleDestructible::setMaxChunkDepthOffset is called with a non-zero 
					/// value.
					/// </summary>
					CrumbleSmallestChunks = NxDestructibleParametersFlag::CRUMBLE_SMALLEST_CHUNKS,

					/// <summary>
					/// If set, the DestructibleActor::rayCast function will search within the nearest visible chunk hit for collisions with 
					/// child chunks.  This is used to get a better raycast position and normal, in case the parent collision volume does not 
					/// tightly fit the graphics mesh.  The returned chunk index will always be that of the visible parent that is intersected, 
					/// however.
					/// </summary>
					AccurateRaycasts = NxDestructibleParametersFlag::ACCURATE_RAYCASTS,

					/// <summary>
					/// If set, the validBounds field of DestructibleParameters will be used.  These bounds are translated (but not scaled or 
					/// rotated) to the origin of the destructible actor.  If a chunk or chunk island moves outside of those bounds, it is 
					/// destroyed.
					/// </summary>
					UseValidBounds = NxDestructibleParametersFlag::USE_VALID_BOUNDS,

					/// <summary>
					/// If set, chunk crumbling will be handled via the pattern-based runtime fracture pipeline. If no fracture pattern is 
					/// specified in the DestructibleActorDesc, or no fracture pattern has been assigned to the destructible actor, chunks will 
					/// simply be removed.
					/// </summary>
					CrumbleViaRuntimeFracture = NxDestructibleParametersFlag::CRUMBLE_VIA_RUNTIME_FRACTURE
				};

				public enum class DestructibleActorRaycastFlags
				{
					StaticChunks = NxDestructibleActorRaycastFlags::StaticChunks,
					DynamicChunks = NxDestructibleActorRaycastFlags::DynamicChunks,

					AllChunks = NxDestructibleActorRaycastFlags::AllChunks,

					SegmentIntersect = NxDestructibleActorRaycastFlags::SegmentIntersect,

					ForceAccurateRaycastsOn = NxDestructibleActorRaycastFlags::ForceAccurateRaycastsOn,
					ForceAccurateRaycastsOff = NxDestructibleActorRaycastFlags::ForceAccurateRaycastsOff
				};

				public enum class DestructibleEmitterType
				{
					Crumble = NxDestructibleEmitterType::Crumble,
					Dust = NxDestructibleEmitterType::Dust
				};
			};
		};
	};
};