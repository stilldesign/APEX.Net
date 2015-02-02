#pragma once

namespace PhysX
{
namespace Apex
{
	namespace Modules
	{
		public ref class ModuleAttribute : Attribute
		{
		public:
			ModuleAttribute(String^ name);

			property String^ Name;
		};
	};
};
};