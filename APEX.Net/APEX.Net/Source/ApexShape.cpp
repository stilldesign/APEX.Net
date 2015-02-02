#include "StdAfx.h"
#include "ApexShape.h"
#include "ApexSdk.h"

using namespace PhysX;

ApexShape::ApexShape(NxApexShape* shape, PhysX::Apex::ApexSdk^ apexSdk)
{
	ThrowIfNull(shape, "shape");
	ThrowIfNullOrDisposed(apexSdk, "apexSdk");

	_shape = shape;
	_apexSdk = apexSdk;
}

ApexShape::~ApexShape()
{
	this->!ApexShape();
}
ApexShape::!ApexShape()
{
	if (Disposed)
		return;

	OnDisposing(this, nullptr);

	_shape->releaseApexShape();
	_shape = NULL;

	OnDisposed(this, nullptr);
}

bool ApexShape::Disposed::get()
{
	return _shape == NULL;
}

bool ApexShape::IntersectAgainstAABB(Bounds3 bounds)
{
	return _shape->intersectAgainstAABB(Bounds3::ToUnmanaged(bounds));
}

Bounds3 ApexShape::GetAABB()
{
	PxBounds3 b = _shape->getAABB();

	return Bounds3::ToManaged(&b);
}

ApexSdk^ ApexShape::ApexSdk::get()
{
	return _apexSdk;
}

Matrix ApexShape::Pose::get()
{
	return MathUtil::PxMat44ToMatrix(&_shape->getPose());
}
void ApexShape::Pose::set(Matrix value)
{
	_shape->setPose(MathUtil::MatrixToPxMat44(value));
}

Matrix ApexShape::PreviousPose::get()
{
	return MathUtil::PxMat44ToMatrix(&_shape->getPreviousPose());
}

NxApexShape* ApexShape::UnmanagedPointer::get()
{
	return _shape;
}