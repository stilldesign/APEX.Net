#include "StdAfx.h"
#include "Parameter.h"
#include "Range.h"

ApexParameter ApexParameter::ToManaged(NxApexParameter param)
{
	PhysX::Apex::Range<int> r(param.range.minimum, param.range.maximum);

	ApexParameter p;
		p.Name = Util::ToManagedString(param.name);
		p.Range = r;
		p.Current = param.current;
		
	return p;
}
NxApexParameter ApexParameter::ToUnmanaged(ApexParameter param)
{
	NxApexParameter p;
		p.name = Util::ToUnmanagedString(param.Name);
		p.range = NxRange<PxU32>(param.Range.Minimum, param.Range.Maximum);
		p.current = param.Current;
		
	return p;
}