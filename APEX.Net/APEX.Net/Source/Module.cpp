#include "StdAfx.h"
#include "Module.h"
#include "ApexSdk.h"
#include "Interface.h"
#include "Parameter.h"

using namespace PhysX::Apex::Modules;

Module::Module()
{
	
}
Module::~Module()
{
	this->!Module();
}
Module::!Module()
{
	OnDisposing(this, nullptr);

	if (Disposed)
		return;

	_owner->UnmanagedPointer->releaseModule(_module);
	_module = NULL;

	OnDisposed(this, nullptr);
}
bool Module::Disposed::get()
{
	return _module == NULL;
}

void Module::Init(NxModule* module, ApexSdk^ owner)
{
	if (module == NULL)
		throw gcnew ArgumentNullException("module");
	ThrowIfNullOrDisposed(owner, "owner");

	_module = module;
	_owner = owner;

	ObjectTable::Add((intptr_t)module, this, owner);
}

void Module::Initalize(Interface^ i)
{
	ThrowIfNullOrDisposed(i, "i");

	_module->init(*i->UnmanagedPointer);
}

array<ApexParameter^>^ Module::GetParameters()
{
	int n = _module->getNbParameters();

	NxApexParameter** cparameters = _module->getParameters();
	
	array<ApexParameter^>^ parameters = gcnew array<ApexParameter^>(n);
	for (int i = 0; i < n; i++)
	{
		ApexParameter^ p = ApexParameter::ToManaged(*cparameters[i]);

		parameters[i] = p;
	}

	return parameters;
}

Interface^ Module::GetDefaultModuleDesc()
{
	NxParameterized::Interface* i = _module->getDefaultModuleDesc();

	return gcnew Interface(i, _owner);
}
void Module::SetInterfaceValue(int parameterIndex, int value)
{
	return _module->setIntValue(parameterIndex, value);
}

//

String^ Module::Name::get()
{
	return Util::ToManagedString(_module->getName());
}

int Module::ModuleId::get()
{
	return _module->getModuleID();
}

float Module::LodBenefitWeight::get()
{
	return _module->getLODBenefitValue();
}
void Module::LodBenefitWeight::set(float value)
{
	_module->setLODBenefitValue(value);
}

NxModule* Module::UnmanagedPointer::get()
{
	return _module;
}