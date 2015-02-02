#pragma once

#include "Range.h"

namespace PhysX
{
	namespace Apex
	{
		public value class ApexParameter
		{
			internal:
				static ApexParameter ToManaged(NxApexParameter param);
				static NxApexParameter ToUnmanaged(ApexParameter param);

			public:
				property String^ Name;
				property PhysX::Apex::Range<int> Range;
				property int Current;
		};
	};
};