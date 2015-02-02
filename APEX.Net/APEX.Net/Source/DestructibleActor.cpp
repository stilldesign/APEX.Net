#include "StdAfx.h"
#include "DestructibleActor.h"
#include "DestructibleAsset.h"
#include "DestructibleParameters.h"
#include "module\destructible\public\NxDestructibleActor.h"

using namespace PhysX::Apex::Modules::Destructible;

DestructibleActor::DestructibleActor(NxDestructibleActor* destructibleActor, DestructibleAsset^ destructibleAsset)
:ApexActor(destructibleActor, destructibleAsset)
{
	ThrowIfNull(destructibleActor, "destructibleActor");

	_destructibeActor = destructibleActor;

	ObjectTable::Add((intptr_t)destructibleActor, this, destructibleAsset);
}
DestructibleActor::~DestructibleActor()
{
	this->!DestructibleActor();
}
DestructibleActor::!DestructibleActor()
{
	
}

void DestructibleActor::ApplyDamage(float damage, float momentum, Vector3 position, Vector3 direction, [Optional] Nullable<int> chunkIndex)
{
	_destructibeActor->applyDamage(
		damage,
		momentum,
		UV(position),
		UV(direction),
		chunkIndex.GetValueOrDefault(NxModuleDestructibleConst::INVALID_CHUNK_INDEX));
}

void DestructibleActor::ApplyRadiusDamage(float damage, float momentum, Vector3 position, float radius, bool falloff)
{
	_destructibeActor->applyRadiusDamage(damage, momentum, UV(position), radius, falloff);
}

void DestructibleActor::DisableHardSleeping()
{
	_destructibeActor->disableHardSleeping();
}
void DestructibleActor::DisableHardSleeping(bool wake)
{
	_destructibeActor->disableHardSleeping(wake);
}

void DestructibleActor::EnableHardSleeping()
{
	_destructibeActor->enableHardSleeping();
}

bool DestructibleActor::ForceChunkHits(array<DestructibleHitChunk>^ hitChunkContainer)
{
	return ForceChunkHits(hitChunkContainer, true, false, Vector3::Zero, Vector3::Zero);
}
bool DestructibleActor::ForceChunkHits(array<DestructibleHitChunk>^ hitChunkContainer, bool removeChunks, bool deferredEvent, Vector3 damagePosition, Vector3 damageDirection)
{
	ThrowIfNull(hitChunkContainer, "hitChunkContainer");

	pin_ptr<DestructibleHitChunk> hcc_pin = &hitChunkContainer[0];
	NxDestructibleHitChunk* hcc = new NxDestructibleHitChunk[hitChunkContainer->Length];
	memcpy(hcc, hcc_pin, sizeof(DestructibleHitChunk) * hitChunkContainer->Length);

	return _destructibeActor->forceChunkHits(
		hcc,
		hitChunkContainer->Length,
		removeChunks,
		deferredEvent,
		UV(damagePosition),
		UV(damageDirection));
}

PhysX::Bounds3 DestructibleActor::GetChunkBounds(int chunkIndex)
{
	return Bounds3::ToManaged(&_destructibeActor->getChunkBounds(chunkIndex));
}

Vector3 DestructibleActor::GetChunkLinearVelocity(int chunkIndex)
{
	return MV(_destructibeActor->getChunkLinearVelocity(chunkIndex));
}

PhysX::Bounds3 DestructibleActor::GetChunkLocalBounds(int chunkIndex)
{
	return Bounds3::ToManaged(&_destructibeActor->getChunkLocalBounds(chunkIndex));
}

Matrix DestructibleActor::GetChunkPose(int chunkIndex)
{
	return MathUtil::PxMat44ToMatrix(&_destructibeActor->getChunkPose(chunkIndex));
}

Matrix DestructibleActor::GetChunkTransform(int chunkIndex)
{
	return MathUtil::PxMat44ToMatrix((PxMat44*)(&_destructibeActor->getChunkTM(chunkIndex)));
}

PhysX::Apex::Modules::Destructible::DestructibleParameters^ DestructibleActor::DestructibleParameters::get()
{
	NxDestructibleParameters p = _destructibeActor->getDestructibleParameters();

	return PhysX::Apex::Modules::Destructible::DestructibleParameters::ToManaged(p);
}
void DestructibleActor::DestructibleParameters::set(PhysX::Apex::Modules::Destructible::DestructibleParameters^ value)
{
	ThrowIfNull(value, "value");

	NxDestructibleParameters p = PhysX::Apex::Modules::Destructible::DestructibleParameters::ToUnmanaged(value);

	_destructibeActor->setDestructibleParameters(p);
}

Nullable<Matrix> DestructibleActor::GlobalPose::get()
{
	PxMat44 pose;

	if (_destructibeActor->getGlobalPose(pose))
		return Nullable<Matrix>();
	else
		return Nullable<Matrix>(MathUtil::PxMat44ToMatrix(&pose));
}
void DestructibleActor::GlobalPose::set(Nullable<Matrix> value)
{
	_destructibeActor->setGlobalPose(MathUtil::MatrixToPxMat44(value.GetValueOrDefault(Matrix::Identity)));
}

Matrix DestructibleActor::InitialGlobalPose::get()
{
	return MathUtil::PxMat44ToMatrix(&_destructibeActor->getInitialGlobalPose());
}
void DestructibleActor::InitialGlobalPose::set(Matrix value)
{
	_destructibeActor->setInitialGlobalPose(MathUtil::MatrixToPxMat44(value));
}

PhysX::Bounds3 DestructibleActor::LocalBounds::get()
{
	return PhysX::Bounds3::ToManaged(&_destructibeActor->getLocalBounds());
}

int DestructibleActor::NumberOfVisibleChunks::get()
{
	return _destructibeActor->getNumVisibleChunks();
}

PhysX::Bounds3 DestructibleActor::OriginalBounds::get()
{
	return PhysX::Bounds3::ToManaged(&_destructibeActor->getOriginalBounds());
}

Vector3 DestructibleActor::Scale::get()
{
	return MV(_destructibeActor->getScale());
}

int DestructibleActor::SupportDepth::get()
{
	return _destructibeActor->getSupportDepth();
}

array<int>^ DestructibleActor::GetVisibleChunks()
{
	int n = _destructibeActor->getNumVisibleChunks();

	auto vc = gcnew array<int>(n);

	const PxU16* x = _destructibeActor->getVisibleChunks();

	for (int i = 0; i < n; i++)
	{
		vc[i] = (int)x[i];
	}

	return vc;
}

bool DestructibleActor::IsChunkDestroyed(int chunkIndex)
{
	return _destructibeActor->isChunkDestroyed(chunkIndex);
}

bool DestructibleActor::IsChunkSolitary(int chunkIndex)
{
	return _destructibeActor->isChunkSolitary(chunkIndex);
}

bool DestructibleActor::IsDynamic(int chunkIndex)
{
	return _destructibeActor->isDynamic(chunkIndex);
}

bool DestructibleActor::IsHardSleepingEnabled::get()
{
	return _destructibeActor->isHardSleepingEnabled();
}

bool DestructibleActor::IsInitiallyDynamic::get()
{
	return _destructibeActor->isInitiallyDynamic();
}

int DestructibleActor::RayCast(float time, Vector3 normal, Vector3 worldRayOrig, Vector3 worldRayDir, DestructibleActorRaycastFlags flags, [Optional] Nullable<int> parentChunkIndex)
{
	return _destructibeActor->rayCast
	(
		time,
		UV(normal),
		UV(worldRayOrig),
		UV(worldRayDir),
		ToUnmanagedEnum(NxDestructibleActorRaycastFlags, flags),
		parentChunkIndex.GetValueOrDefault(NxModuleDestructibleConst::INVALID_CHUNK_INDEX)
	);
}

bool DestructibleActor::RecreateApexEmitter(DestructibleEmitterType type)
{
	return _destructibeActor->recreateApexEmitter(ToUnmanagedEnum(NxDestructibleEmitterType, type));
}

bool DestructibleActor::ReleaseChunkEventBuffer()
{
	return ReleaseChunkEventBuffer(true);
}
bool DestructibleActor::ReleaseChunkEventBuffer(bool clearBuffer)
{
	return _destructibeActor->releaseChunkEventBuffer(clearBuffer);
}

bool DestructibleActor::ReleasePhysXActorBuffer()
{
	return _destructibeActor->releasePhysXActorBuffer();
}

void DestructibleActor::SetAngularVelocityOfAllChunks(Vector3 angularVelocity)
{
	return _destructibeActor->setAngularVelocity(UV(angularVelocity));
}

void DestructibleActor::SetCrumbleEmitterState(bool enable)
{
	_destructibeActor->setCrumbleEmitterState(enable);
}

void DestructibleActor::SetDeleteFracturedChunks(bool inDeleteChunkMode)
{
	_destructibeActor->setDeleteFracturedChunks(inDeleteChunkMode);
}

void DestructibleActor::SetDustEmitterState(bool enable)
{
	_destructibeActor->setDustEmitterState(enable);
}

void DestructibleActor::SetAllChunksAsDynamic()
{
	_destructibeActor->setDynamic();
}

void DestructibleActor::SetChunkAsDynamic(int chunkIndex)
{
	_destructibeActor->setDynamic(chunkIndex);
}

bool DestructibleActor::SetHitChunkTrackingParams(bool flushHistory, bool startTracking, int trackingDepth)
{
	return SetHitChunkTrackingParams(flushHistory, startTracking, trackingDepth, true);
}
bool DestructibleActor::SetHitChunkTrackingParams(bool flushHistory, bool startTracking, int trackingDepth, bool trackAllChunks)
{
	return _destructibeActor->setHitChunkTrackingParams(flushHistory, startTracking, trackingDepth, trackAllChunks);
}

void DestructibleActor::SetLinearVelocityOfAllChunks(Vector3 linearVelocity)
{
	_destructibeActor->setLinearVelocity(UV(linearVelocity));
}

void DestructibleActor::SetLODWeights(float maxDistance, float distanceWeight, float maxAge, float ageWeight, float bias)
{
	_destructibeActor->setLODWeights(maxDistance, distanceWeight, maxAge, ageWeight, bias);
}

void DestructibleActor::SetRuntimeFractureOverridePattern(String^ overridePatternName)
{
	_destructibeActor->setRuntimeFractureOverridePattern(Util::ToUnmanagedString(overridePatternName));
}

void DestructibleActor::SetSkinnedOverrideMaterial(int submeshIndex, String^ overrideMaterialName)
{
	_destructibeActor->setSkinnedOverrideMaterial(submeshIndex, Util::ToUnmanagedString(overrideMaterialName));
}

void DestructibleActor::SetStaticOverrideMaterial(int submeshIndex, String^ overrideMaterialName)
{
	_destructibeActor->setStaticOverrideMaterial(submeshIndex, Util::ToUnmanagedString(overrideMaterialName));
}

//

NxDestructibleActor* DestructibleActor::UnmanagedPointer::get()
{
	return _destructibeActor;
}