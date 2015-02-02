#include "StdAfx.h"
#include "Vertex.h"

Vertex Vertex::ToManaged(NxVertex vertex)
{
	Vertex v;
	
	pin_ptr<Vertex> pv = &v;

	memcpy_s(pv, sizeof(Vertex), &vertex, sizeof(NxVertex));

	return v;
}