#include "StdAfx.h"
#include "DestructibleParameters.h"

using namespace PhysX::Apex::Modules::Destructible;

DestructibleParameters^ DestructibleParameters::ToManaged(NxDestructibleParameters unmanaged)
{
	auto p = gcnew DestructibleParameters();

	p->DamageCap = unmanaged.damageCap;
	p->ForceToDamage = unmanaged.forceToDamage;
	p->ImpactVelocityThreshold = unmanaged.impactVelocityThreshold;
	p->MinimumFractureDepth = unmanaged.minimumFractureDepth;
	p->ImpactDamageDefaultDepth = unmanaged.impactDamageDefaultDepth;
	p->DebrisDepth = unmanaged.debrisDepth;
	p->EssentialDepth = unmanaged.essentialDepth;
	p->DebrisLifetimeMin = unmanaged.debrisLifetimeMin;
	p->DebrisLifetimeMax = unmanaged.debrisLifetimeMax;
	p->DebrisMaxSeparationMin = unmanaged.debrisMaxSeparationMin;
	p->DebrisMaxSeparationMax = unmanaged.debrisMaxSeparationMax;
	p->DebrisDestructionProbability = unmanaged.debrisDestructionProbability;
	p->ValidBounds = PhysX::Bounds3::ToManaged(&unmanaged.validBounds);
	p->MaxChunkSpeed = unmanaged.maxChunkSpeed;
	p->Flags = unmanaged.flags;
	p->FractureImpulseScale = unmanaged.fractureImpulseScale;
	p->DamageDepthLimit = unmanaged.damageDepthLimit;
	p->DynamicChunksDominanceGroup = unmanaged.dynamicChunksDominanceGroup;
	p->UseDynamicChunksGroupsMask = unmanaged.useDynamicChunksGroupsMask;
	p->DepthParametersCount = unmanaged.depthParametersCount;

	return p;
}
NxDestructibleParameters DestructibleParameters::ToUnmanaged(DestructibleParameters^ managed)
{
	NxDestructibleParameters p;

	p.damageCap = managed->DamageCap;
	p.forceToDamage = managed->ForceToDamage;
	p.impactVelocityThreshold = managed->ImpactVelocityThreshold;
	p.minimumFractureDepth = managed->MinimumFractureDepth;
	p.impactDamageDefaultDepth = managed->ImpactDamageDefaultDepth;
	p.debrisDepth = managed->DebrisDepth;
	p.essentialDepth = managed->EssentialDepth;
	p.debrisLifetimeMin = managed->DebrisLifetimeMin;
	p.debrisLifetimeMax = managed->DebrisLifetimeMax;
	p.debrisMaxSeparationMin = managed->DebrisMaxSeparationMin;
	p.debrisMaxSeparationMax = managed->DebrisMaxSeparationMax;
	p.debrisDestructionProbability = managed->DebrisDestructionProbability;
	p.validBounds = PhysX::Bounds3::ToUnmanaged(managed->ValidBounds);
	p.maxChunkSpeed = managed->MaxChunkSpeed;
	p.flags = managed->Flags;
	p.fractureImpulseScale = managed->FractureImpulseScale;
	p.damageDepthLimit = managed->DamageDepthLimit;
	p.dynamicChunksDominanceGroup = managed->DynamicChunksDominanceGroup;
	p.useDynamicChunksGroupsMask = managed->UseDynamicChunksGroupsMask;
	p.depthParametersCount = managed->DepthParametersCount;

	return p;
}