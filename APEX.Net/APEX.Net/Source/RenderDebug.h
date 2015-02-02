#pragma once

namespace PhysX
{
	namespace Apex
	{
		ref class ApexSdk;

		public ref class RenderDebug : IDisposable
		{
			public:
				/// <summary>Raised before any disposing is performed.</summary>
				virtual event EventHandler^ OnDisposing;
				/// <summary>Raised once all disposing is performed.</summary>
				virtual event EventHandler^ OnDisposed;

			private:
				NxApexRenderDebug* _debug;
				ApexSdk^ _owner;

			protected:
				RenderDebug(NxApexRenderDebug* debug, ApexSdk^ owner);
			public:
				~RenderDebug();
			protected:
				!RenderDebug();

			public:
				property bool Disposed
				{
					virtual bool get();
				}

				//PhysX::DebugRenderable^ GetDebugRenderable();
		};
	};
};