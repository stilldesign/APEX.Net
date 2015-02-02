#pragma once

#include "ApexShape.h"

namespace PhysX
{
	namespace Apex
	{
		ref class Physics;

		public ref class ApexBoxShape : ApexShape
		{
		internal:
			ApexBoxShape(NxApexBoxShape* shape, PhysX::Apex::ApexSdk^ apexSdk);

		public:
			property Vector3 Size
			{
				Vector3 get();
				void set(Vector3 value);
			}

		internal:
			property NxApexBoxShape* UnmanagedPointer
			{
				NxApexBoxShape* get();
			}
		};
	};
};