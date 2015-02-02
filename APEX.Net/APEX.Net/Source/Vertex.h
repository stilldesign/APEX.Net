#pragma once

#include "VertexColor.h"

using namespace System::Runtime::InteropServices;

namespace PhysX
{
	namespace Apex
	{
		[StructLayout(LayoutKind::Sequential)]
		public value class Vertex
		{
			internal:
				static Vertex ToManaged(NxVertex vertex);

			public:
				Vector3 Position;
				Vector3 Normal;
				Vector3 Tangent;
				Vector3 Binormal;
				Vector2 UV0;
				Vector2 UV1;
				Vector2 UV2;
				Vector2 UV3;
				VertexColor Color;
				short BoneIndices0;
				short BoneIndices1;
				short BoneIndices2;
				short BoneIndices3;
				float BoneWeight0;
				float BoneWeight1;
				float BoneWeight2;
				float BoneWeight3;
		};
	};
};