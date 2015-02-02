#include "StdAfx.h"
#include "ApexBoxShape.h"

ApexBoxShape::ApexBoxShape(NxApexBoxShape* shape, PhysX::Apex::ApexSdk^ apexSdk)
: ApexShape(shape, apexSdk)
{

}

Vector3 ApexBoxShape::Size::get()
{
	return MV(this->UnmanagedPointer->getSize());
}
void ApexBoxShape::Size::set(Vector3 value)
{
	this->UnmanagedPointer->setSize(UV(value));
}

NxApexBoxShape* ApexBoxShape::UnmanagedPointer::get()
{
	return (NxApexBoxShape*)((ApexShape^)this)->UnmanagedPointer;
}