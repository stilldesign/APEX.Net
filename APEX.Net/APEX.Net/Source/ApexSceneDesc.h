#pragma once

namespace PhysX
{
	namespace Apex
	{
		public ref class ApexSceneDesc
		{
		internal:
			static NxApexSceneDesc ToUnmanaged(ApexSceneDesc^ managed);

		public:
			property bool UseDebugRenderable;
			property bool DebugVisualizeRemotely;
			property bool DebugVisualizeLocally;
			//property bool EnableGpuRigidBodyPhysics;
		};
	};
};