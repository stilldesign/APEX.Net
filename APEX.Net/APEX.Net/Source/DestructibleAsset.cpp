#include "StdAfx.h"
#include "DestructibleAsset.h"
#include "Asset.h"

using namespace PhysX::Apex::Modules::Destructible;

DestructibleAsset::DestructibleAsset(NxDestructibleAsset* destructibleAsset, ApexSdk^ owner)
: Asset(destructibleAsset, owner)
{
}
