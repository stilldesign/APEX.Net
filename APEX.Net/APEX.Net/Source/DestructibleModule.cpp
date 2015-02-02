#include "StdAfx.h"
#include "DestructibleModule.h"

using namespace PhysX::Apex::Modules::Destructible;

NxModuleDestructible* DestructibleModule::UnmanagedPointer::get()
{
	return (NxModuleDestructible*)Module::UnmanagedPointer;
}