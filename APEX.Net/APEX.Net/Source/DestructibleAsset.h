#pragma once

#include <module\destructible\public\NxDestructibleAsset.h>
#include "Asset.h"

namespace PhysX
{
	namespace Apex
	{
		ref class ApexAsset;

		namespace Modules
		{
			namespace Destructible
			{
				public ref class DestructibleAsset : Asset
				{
				internal:
					DestructibleAsset(NxDestructibleAsset* destructibleAsset, ApexSdk^ owner);

				public:
					
				};
			}
		}
	}
}