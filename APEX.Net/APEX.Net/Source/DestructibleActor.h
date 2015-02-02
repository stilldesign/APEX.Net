#pragma once

#include "DestructibleHitChunk.h"
#include "DestructibleEnum.h"
#include "ApexActor.h"

namespace PhysX
{
	namespace Apex
	{
		namespace Modules
		{
			namespace Destructible
			{
				ref class DestructibleParameters;
				ref class DestructibleAsset;

				public ref class DestructibleActor : ApexActor
				{
				private:
					NxDestructibleActor* _destructibeActor;

				protected:
					DestructibleActor(NxDestructibleActor* destructibleActor, DestructibleAsset^ destructibleAsset);
				public:
					~DestructibleActor();
				protected:
					!DestructibleActor();

				public:
					///// <summary>
					///// Locks the chunk event buffer, and (if successful) returns the head of the chunk event buffer in the buffer field and 
					///// the length of the buffer (the number of events) in the bufferSize field. To unlock the buffer, use 
					///// releaseChunkEventBuffer(). See NxDestructibleChunkEvent. This buffer is filled with chunk events if the 
					///// NxDestructibleActor parameter createChunkEvents is set to true. This buffer is not automatically cleared by APEX. The 
					///// user must clear it using releaseChunkEventBuffer(true). Returns true if successful, false otherwise. 
					///// </summary>
					//bool AcquireChunkEventBuffer(physx::NxDestructibleChunkEvent * buffer, int bufferSize );

					///// <summary>
					///// Acquire a pointer to the destructible's renderable proxy and increment its reference count. The 
					///// NxDestructibleRenderable will only be deleted when its reference count is zero. Calls to 
					///// NxDestructibleRenderable::release decrement the reference count, as does a call to NxDestructibleActor::release(). . 
					///// </summary>
					//NxDestructibleRenderable* AcquireRenderableReference();

					/// <summary>
					/// Damage Apply damage at a point. Damage will be propagated into the destructible based upon its 
					/// NxDestructibleParameters. damage = the amount of damage at the damage point momentum = the magnitude of the impulse to 
					/// transfer to the actor position = the damage location direction = direction of impact. This is valid even if momentum = 
					/// 0, for use in deformation calculations. chunkIndex = which chunk to damage (returned by rayCast and 
					/// NxModuleDestructible::getDestructibleAndChunk). If chunkIndex = NxModuleDestructibleConst::INVALID_CHUNK_INDEX, then 
					/// the nearest visible chunk hit is found. userData = pointer which will be returned in damage and fracture event 
					/// callbacks 
					/// </summary>
					void ApplyDamage(float damage, float momentum, Vector3 position, Vector3 direction, [Optional] Nullable<int> chunkIndex);

					/// <summary>
					/// Apply damage to all chunks within a radius. Damage will also propagate into the destructible based upon its 
					/// NxDestructibleParameters. damage = the amount of damage at the damage point momentum = the magnitude of the impulse to 
					/// transfer to each chunk position = the damage location radius = distance from damage location at which chunks will be 
					/// affected falloff = whether or not to decrease damage with distance from the damage location. If true, damage will 
					/// decrease linearly from the full damage (at zero distance) to zero damage (at radius). If false, full damage is applied 
					/// to all chunks within the radius. userData = pointer which will be returned in damage and fracture event callbacks 
					/// </summary>
					void ApplyRadiusDamage(float damage, float momentum, Vector3 position, float radius, bool falloff);

					/// <summary>
					/// See the comments for enableHardSleeping() for a description of this feature. The disableHardSleeping function takes a 
					/// "wake" parameter, which (if true) will not only turn kinematic-sleeping actors dynamic, but wake them as well. 
					/// </summary>
					void DisableHardSleeping();
					/// <summary>
					/// See the comments for enableHardSleeping() for a description of this feature. The disableHardSleeping function takes a 
					/// "wake" parameter, which (if true) will not only turn kinematic-sleeping actors dynamic, but wake them as well. 
					/// </summary>
					void DisableHardSleeping(bool wake);

					/// <summary>
					/// If "hard sleeping" is enabled, physx actors for chunk islands that go to sleep will be turned kinematic. If a chunk 
					/// island has chunks from more than one NxDestructibleActor, then hard sleeping will be used if ANY of the destructibles 
					/// have hard sleeping enabled. 
					/// </summary>
					void EnableHardSleeping();

					/// <summary>
					/// Force the actor to register chunk hits.
					/// </summary>
					bool ForceChunkHits(array<DestructibleHitChunk>^ hitChunkContainer);
					/// <summary>
					/// Force the actor to register chunk hits.
					/// </summary>
					bool ForceChunkHits(array<DestructibleHitChunk>^ hitChunkContainer, bool removeChunks, bool deferredEvent, Vector3 damagePosition, Vector3 damageDirection);

					///// <summary>
					///// Force the actor to register damage coloring.
					///// </summary>
					//bool ForceDamageColoring(NxDamageEventCoreData * damageEventCoreDataContainer, int damageEventCoreDataCount );

					///// <summary>
					///// Returns the NxApexEmitterActor of either a dust or crumble emitter Note - only crumble emitters are implemented in 
					///// 1.2.0 
					///// </summary>
					//NxApexEmitterActor* GetApexEmitter(NxDestructibleEmitterType::Enum type);

					///// <summary>
					///// Access to behavior groups created for this actor. Each chunk has a behavior group index associated with it.
					///// </summary>
					//bool GetBehaviorGroup(physx::NxDestructibleBehaviorGroupDesc behaviorGroupDesc, int index = -1);

					///// <summary>
					///// Returns the behavior group index associated with the chunk. Use getBehaviorGroup() to access the behavior group data. 
					///// The index will either be -1, in which case it is the default behavior group, or in the range [0, 
					///// getCustomBehaviorGroupCount()-1]. Any of those values is valid for getBehaviorGroup(). 
					///// </summary>
					//int GetBehaviorGroupIndex(int chunkIndex);

					///// <summary>
					///// Returns a chunk's angular velocity in world space. index = the chunk index within the actor 
					///// </summary>
					//Vector3 GetChunkAngularVelocity(int chunkIndex);

					/// <summary>
					/// Accessor to query the axis aligned bounding box of a given chunk in world-space. 
					/// </summary>
					Bounds3 GetChunkBounds(int chunkIndex);

					/// <summary>
					/// Returns a chunk's linear velocity in world space. index = the chunk index within the actor 
					/// </summary>
					Vector3 GetChunkLinearVelocity(int chunkIndex);

					/// <summary>
					/// Accessor to query the axis aligned bounding box of a given chunk in chunk local-space. 
					/// </summary>
					Bounds3 GetChunkLocalBounds(int chunkIndex);

					/// <summary>
					/// Returns the PhysX actor associated with the given chunk. Note, more than one chunk may be associated with a given PhysX 
					/// actor, and chunks from different NxDestructibleActors may even be associated with the same PhysX actor. Caution is 
					/// recommended when using this function. During APEX scene simulate/fetchResults, this actor may be deleted, replaced, or 
					/// tampered with. index = the chunk index within the actor Returns a chunk's pose, without scaling. index = the chunk 
					/// index within the actor 
					/// </summary>
					Matrix GetChunkPose(int chunkIndex);

					/// <summary>
					/// Returns the transform of the chunk's graphical representation. This may have a scale component. index = the chunk index 
					/// within the actor 
					/// </summary>
					Matrix GetChunkTransform(int chunkIndex);

					/// <summary>
					/// Returns an array of visibility data for each chunk. Each byte in the array is 0 if the corresponding chunkIndex is 
					/// invisible, 1 if visibile. visibilityArray = a pointer to the byte buffer to hold the visibility values. 
					/// visibilityArraySize = the size of the visibilityArray 
					/// </summary>
					//array<bool>^ GetChunkVisibilities();

					///// <summary>
					///// Access to behavior groups created for this actor. Each chunk has a behavior group index associated with it.
					///// </summary>
					//int GetCustomBehaviorGroupCount();

					///// <summary>
					///// Get the damage coloring history of the actor. To start caching damage coloring, see setHitChunkTrackingParams()
					///// </summary>
					//bool GetDamageColoringHistory(NxDamageEventCoreData * damageEventCoreDataContainer, int damageEventCoreDataCount );

					/// <summary>
					/// Gets the destructible's NxDestructibleParameter block of parameters. These are initially set from the asset. 
					/// </summary>
					property PhysX::Apex::Modules::Destructible::DestructibleParameters^ DestructibleParameters
					{
						PhysX::Apex::Modules::Destructible::DestructibleParameters^ get();
						void set(PhysX::Apex::Modules::Destructible::DestructibleParameters^ value);
					}

					/// <summary>
					/// Get the destructible actor's global pose. This will be the pose of the physx NxActor or PxActor for the static chunks 
					/// in the structure containing this actor, if there are static chunks. If there are no static chunks in the structure, 
					/// pose will not be modified and false will be returned. Otherwise pose will be filled in with a scale-free transform, and 
					/// true is returned.
					/// 
					/// Set the destructible actor's global pose. This will only be applied to the physx NxActor or PxActor for the static 
					/// chunks, and therefore will apply to all static chunks in the structure which contains the this destructible actor. This 
					/// pose should not contain scale, as the scale is already contained in the actor's scale parameter. 
					/// </summary>
					property Nullable<Matrix> GlobalPose
					{
						Nullable<Matrix> get();
						void set(Nullable<Matrix> value);
					}

					///// <summary>
					///// Get the chunk hit history of the actor. To start caching chunk hits, see setHitChunkTrackingParams()
					///// </summary>
					//bool GetHitChunkHistory(NxDestructibleHitChunk * hitChunkContainer, int hitChunkCount );

					/// <summary>
					/// Gets the global pose used when the actor is added to the scene, in the NxDestructibleActorDesc 
					///
					/// Resets the initial global pose used for support calculations when the first simulation step is run. 
					/// </summary>
					property Matrix InitialGlobalPose
					{
						Matrix get();
						void set(Matrix value);
					}

					/// <summary>
					/// Accessor to get the initial locally-aligned bounding box of a destructible actor. 
					/// </summary>
					property Bounds3 LocalBounds
					{
						Bounds3 get();
					}

					/// <summary>
					/// Returns the number of visible chunks. This is the number of 1's written to the visibilityArray
					/// by getChunkVisibilities. 
					/// </summary>
					property int NumberOfVisibleChunks
					{
						int get();
					}

					///// <summary>
					///// Returns the actor's NxParamaterized interface This cannot be directly modified! It is read only to the user. This 
					///// handle can be used to directly serialize the complete actor state. 
					///// </summary>
					//::NxParameterized::Interface* getNxParameterized(NxDestructibleParameterizedType::Enum type = NxDestructibleParameterizedType::State);

					/// <summary>
					/// Accessor to get the initial world axis-aligned bounding box of a destructible actor. 
					/// </summary>
					property Bounds3 OriginalBounds
					{
						Bounds3 get();
					}

					///// <summary>
					///// Get the render mesh actor for the specified mesh type. 
					///// </summary>
					//NxRenderMeshActor* getRenderMeshActor(NxDestructibleActorMeshType::Enum type = NxDestructibleActorMeshType::Skinned);

					/// <summary>
					/// Gets the destructible actor's 3D (possibly nonuniform) scale 
					/// </summary>
					property Vector3 Scale
					{
						Vector3 get();
					}

					/// <summary>
					/// Query the actor's support depth. 
					/// </summary>
					property int SupportDepth
					{
						int get();
					}

					///// <summary>
					///// Accessor to get the array of chunk indices at the support depth. 
					///// </summary>
					//int getSupportDepthChunkIndices(int * OutChunkIndices, int MaxOutIndices );

					/// <summary>
					/// Returns a pointer to an array of visible chunk indices. 
					/// </summary>
					array<int>^ GetVisibleChunks();

					/// <summary>
					/// Accessor to query if a chunk has been destroyed. 
					/// </summary>
					bool IsChunkDestroyed(int chunkIndex);

					/// <summary>
					/// Accessor to query if a chunk is part of a detached island. 
					/// </summary>
					bool IsChunkSolitary(int chunkIndex);

					/// <summary>
					/// Returns true if the chunkIndex is valid, and the indexed chunk is dynamic. Returns false otherwise. 
					/// </summary>
					bool IsDynamic(int chunkIndex);

					/// <summary>
					/// Returns true iff hard sleeping is selected for this NxDestructibleActor. 
					/// </summary>
					property bool IsHardSleepingEnabled
					{
						bool get();
					}

					/// <summary>
					/// Returns true iff the destructible actor starts off life dynamic. 
					/// </summary>
					property bool IsInitiallyDynamic
					{
						bool get();
					}

					///// <summary>
					///// Physx SDK 2.8.X. Returns the index of the first visible chunk hit in the actor by swept oriented bounding box, if any. 
					///// Otherwise returns NxModuleDestructibleConst::INVALID_CHUNK_INDEX. If a chunk is hit, the time and normal fields are 
					///// modified. time = (return value) of the time to the hit chunk, if any. normal = (return value) the surface normal of the 
					///// hit chunk's collision volume, if any. worldBox = the obb to sweep against the actor, oriented in world space 
					///// worldDisplacement = the displacement of the center of the worldBox through the sweep, in world space flags = raycast 
					///// control flags (see NxDestructibleActorRaycastFlags) 
					///// </summary>
					//int obbSweep(float time, Vector3 normal, NxBox worldBox, Vector3 worldDisplacement, NxDestructibleActorRaycastFlags::Enum flags );

					///// <summary>
					///// Physx SDK 3.X. Returns the index of the first visible chunk hit in the actor by swept oriented bounding box, if any. 
					///// Otherwise returns NxModuleDestructibleConst::INVALID_CHUNK_INDEX. If a chunk is hit, the time and normal fields are 
					///// modified. time = (return value) of the time to the hit chunk, if any. normal = (return value) the surface normal of the 
					///// hit chunk's collision volume, if any. worldBox = the obb to sweep against the actor, oriented in world space 
					///// worldDisplacement = the displacement of the center of the worldBox through the sweep, in world space flags = raycast 
					///// control flags (see NxDestructibleActorRaycastFlags) 
					///// </summary>
					//int obbSweep(float time, Vector3 normal, Vector3 worldBoxCenter, Vector3 worldBoxExtents, physx::PxMat33 worldBoxRot, Vector3 worldDisplacement, NxDestructibleActorRaycastFlags::Enum flags );

					///// <summary>
					///// Register a rigid body impact for impact-based damage. Much like applyDamage, but multplies the input 'force' by the 
					///// destructible's forceToDamage parameter, and also allows the user to report the impacting PhysX actor PhysX SDK 2.8.X. 
					///// Returns the index of the first visible chunk hit in the actor by worldRay, if any. Otherwise returns 
					///// NxModuleDestructibleConst::INVALID_CHUNK_INDEX. If a chunk is hit, the time and normal fields are modified. time = 
					///// (return value) of the time to the hit chunk, if any. normal = (return value) the surface normal of the hit chunk's 
					///// collision volume, if any. worldRay = the ray to fire at the actor (the direction need not be normalized) flags = 
					///// raycast control flags (see NxDestructibleActorRaycastFlags) parentChunkIndex = (if not equal to 
					///// NxModuleDestructibleConst::INVALID_CHUNK_INDEX) the chunk subhierarchy in which to confine the raycast. If 
					///// parentChunkIndex = NxModuleDestructibleConst::INVALID_CHUNK_INDEX, then the whole actor is searched. 
					///// </summary>
					//int rayCast(float time, Vector3 normal, NxRay worldRay, NxDestructibleActorRaycastFlags::Enum flags, int parentChunkIndex = NxModuleDestructibleConst::INVALID_CHUNK_INDEX );

					/// <summary>
					/// PhysX SDK 3.X. Returns the index of the first visible chunk hit in the actor by worldRay, if any. Otherwise returns 
					/// NxModuleDestructibleConst::INVALID_CHUNK_INDEX. If a chunk is hit, the time and normal fields are modified. time = 
					/// (return value) of the time to the hit chunk, if any. normal = (return value) the surface normal of the hit chunk's 
					/// collision volume, if any. worldRay = the ray to fire at the actor (the direction need not be normalized) flags = 
					/// raycast control flags (see NxDestructibleActorRaycastFlags) parentChunkIndex = (if not equal to 
					/// NxModuleDestructibleConst::INVALID_CHUNK_INDEX) the chunk subhierarchy in which to confine the raycast. If 
					/// parentChunkIndex = NxModuleDestructibleConst::INVALID_CHUNK_INDEX, then the whole actor is searched. 
					/// </summary>
					int RayCast(float time, Vector3 normal, Vector3 worldRayOrig, Vector3 worldRayDir, DestructibleActorRaycastFlags flags, [Optional] Nullable<int> parentChunkIndex);

					/// <summary>
					/// Recreates the Apex Emitter, if necessary. Use this method to re-initialize the crumble or dust emitter after a change 
					/// has been made to a dependent asset Note - only crumble emitters are implemented in 1.2.0 
					/// </summary>
					bool RecreateApexEmitter(DestructibleEmitterType type);

					/// <summary>
					/// Releases the chunk event buffer, which may have been locked by acquireChunkEventBuffer(). If clearBuffer is true, the 
					/// buffer will be erased before it is unlocked. Returns true if successful, false otherwise. 
					/// </summary>
					bool ReleaseChunkEventBuffer();
					/// <summary>
					/// Releases the chunk event buffer, which may have been locked by acquireChunkEventBuffer(). If clearBuffer is true, the 
					/// buffer will be erased before it is unlocked. Returns true if successful, false otherwise. 
					/// </summary>
					bool ReleaseChunkEventBuffer(bool clearBuffer);

					/// <summary>
					/// Locks a PhysX actor buffer, and (if successful) returns the head of the buffer in the buffer field and the length of 
					/// the buffer (the number of PhysX actors) in the bufferSize field. To unlock the buffer, use releasePhysXActorBuffer(). 
					/// The user must release this buffer before another call to releasePhysXActorBuffer. buffer = returned buffer, if 
					/// successful bufferSize = returned buffer size, if successful flags = flags which control which actors are returned. See 
					/// NxDestructiblePhysXActorQueryFlags. eliminateRedundantActors = whether or not to ensure that PhysX actors are not 
					/// listed more than once when this NxDestructibleActor is part of an extended structure. If this is true, then some 
					/// NxDestructibleActors may not return all PhysX actors associated with all of their chunks (and in fact may return no 
					/// PhysX actors), but after querying all NxDestructibleActors in a given structure, every PhysX actor will be accounted 
					/// for. Default = true. Returns true if successful, false otherwise. Releases the PhysX actor buffer, which may have been 
					/// locked by acquirePhysXActorBuffer(). The buffer will be erased before it is unlocked. Returns true if successful, false 
					/// otherwise. 
					/// </summary>
					bool ReleasePhysXActorBuffer();

					/// <summary>
					/// Sets the angular velocity of every dynamic chunk to the given value. 
					/// </summary>
					void SetAngularVelocityOfAllChunks(Vector3 angularVelocity);

					/// <summary>
					/// Enable/disable the crumble emitter 
					/// </summary>
					void SetCrumbleEmitterState(bool enable);

					/// <summary>
					/// Set the actor to delete its fractured chunks instead of simulating them. 
					/// </summary>
					void SetDeleteFracturedChunks(bool inDeleteChunkMode);

					///// <summary>
					///// Sets the destructible's NxDestructibleParameter block of parameters. These may be set at runtime. 
					///// </summary>
					//void setDestructibleParameters(NxDestructibleParameters destructibleParameters);

					/// <summary>
					/// Enable/disable the dust emitter Note - this is a placeholder API. The dust feature is disabled in 1.2.0. 
					/// </summary>
					void SetDustEmitterState(bool enable);

					/// <summary>
					/// If the indexed chunk is visible, it is made dynamic (if it is not already). If 
					/// NxModuleDestructibleConst::INVALID_CHUNK_INDEX is passed in, all visible chunks in the destructible actor are made 
					/// dynamic, if they are not already. 
					/// </summary>
					void SetAllChunksAsDynamic();
					/// <summary>
					/// If the indexed chunk is visible, it is made dynamic (if it is not already). If 
					/// NxModuleDestructibleConst::INVALID_CHUNK_INDEX is passed in, all visible chunks in the destructible actor are made 
					/// dynamic, if they are not already. 
					/// </summary>
					void SetChunkAsDynamic(int chunkIndex);

					/// <summary>
					/// Set the tracking properties of the actor for chunks that are hit. Chunks that are hit are chunks directly affected by 
					/// fracture events.
					/// </summary>
					bool SetHitChunkTrackingParams(bool flushHistory, bool startTracking, int trackingDepth);
					/// <summary>
					/// Set the tracking properties of the actor for chunks that are hit. Chunks that are hit are chunks directly affected by 
					/// fracture events.
					/// </summary>
					bool SetHitChunkTrackingParams(bool flushHistory, bool startTracking, int trackingDepth, bool trackAllChunks);

					/// <summary>
					/// Sets the linear velocity of every dynamic chunk to the given value. 
					/// </summary>
					void SetLinearVelocityOfAllChunks(Vector3 linearVelocity);

					/// <summary>
					/// Misc. 
					/// </summary>
					void SetLODWeights(float maxDistance, float distanceWeight, float maxAge, float ageWeight, float bias);

					///// <summary>
					///// Sets the actor's state via the NxParameterized object This can be used to update the state from deserialized data. The 
					///// actor assumes control of the interface. 
					///// </summary>
					//void setNxParameterized(::NxParameterized::Interface *);

					///// <summary>
					///// Sets a preferred render volume for a dust or crumble emitter Note - only crumble emitters are implemented in 1.2.0 
					///// </summary>
					//void setPreferredRenderVolume(NxApexRenderVolume * volume, NxDestructibleEmitterType::Enum type );

					/// <summary>
					/// Sets the override fracture pattern. 
					/// </summary>
					void SetRuntimeFractureOverridePattern(String^ overridePatternName);

					/// <summary>
					/// Sets the override material. 
					/// </summary>
					void SetSkinnedOverrideMaterial(int submeshIndex, String^ overrideMaterialName);

					/// <summary>
					/// Sets the override material. 
					/// </summary>
					void SetStaticOverrideMaterial(int submeshIndex, String^ overrideMaterialName);

					///// <summary>
					///// Set the syncing properties of the destructible actor.
					///// </summary>
					//bool setSyncParams(int userActorID, int actorSyncFlags = 0, NxDestructibleActorSyncState * actorSyncState = nullptr, NxDestructibleChunkSyncState * chunkSyncState = nullptr );

				internal:
					property NxDestructibleActor* UnmanagedPointer
					{
						NxDestructibleActor* get();
					}
				};
			};
		};
	}
}