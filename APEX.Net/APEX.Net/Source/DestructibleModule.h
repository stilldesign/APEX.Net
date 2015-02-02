#pragma once

#include <module\destructible\public\NxModuleDestructible.h>
#include "Module.h"
#include "ModuleAttribute.h"

namespace PhysX
{
namespace Apex
{
namespace Modules
{
	namespace Destructible
	{
		[Module("Destructible")]
		public ref class DestructibleModule : Module
		{
		internal:
			property NxModuleDestructible* UnmanagedPointer
			{
				NxModuleDestructible* get() new;
			}
		};
	};
};
};
};