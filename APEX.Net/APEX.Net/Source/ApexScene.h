#pragma once

#include "Module.h"

namespace PhysX
{
	namespace Apex
	{
		public ref class ApexScene : IDisposable
		{
		public:
			/// <summary>Raised before any disposing is performed.</summary>
			virtual event EventHandler^ OnDisposing;
			/// <summary>Raised once all disposing is performed.</summary>
			virtual event EventHandler^ OnDisposed;

		private:
			NxApexScene* _apexScene;
			NxApexSDK* _SDK;

		public:
			ApexScene(NxApexScene* scene, ApexSdk^ apexSdk);
			~ApexScene();
		protected:
			!ApexScene();

		public:
			property bool Disposed
			{
				virtual bool get();
			}

			

			//

			property NxApexScene* UnmanagedPointer
			{
				NxApexScene* get();
			}
		};
	};
};