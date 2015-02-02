#pragma once

namespace PhysX
{
	namespace Apex
	{
		ref class ApexSdk;
		ref class Interface;
		ref class ApexScene;
		ref class Asset;
		ref class ApexActorGetPhysicalLodRange;

		// TODO abstract
		public ref class ApexActor: IDisposable
		{
		public:
			/// <summary>Raised before any disposing is performed.</summary>
			virtual event EventHandler^ OnDisposing;
			/// <summary>Raised once all disposing is performed.</summary>
			virtual event EventHandler^ OnDisposed;

		private:
			NxApexActor* _apexActor;

		public:
			ApexActor(NxApexActor* apexActor, Asset^ owner);
		public:
			~ApexActor();
		protected:
			!ApexActor();

		public:
			property bool Disposed
			{
				virtual bool get();
			}

			/// <summary>
			/// Returns the owning asset.
			/// </summary>
			property Asset^ Owner
			{
				Asset^ get();
			}

			/// <summary>
			/// Returns the range of possible values for physical Lod overwrite.
			/// </summary>
			property ApexActorGetPhysicalLodRange^ PhysicalLodRange
			{
				ApexActorGetPhysicalLodRange^ get();
			}

			/// <summary>
			/// Get current physical lod.
			/// </summary>
			property float ActivePhysicalLod
			{
				float get();
			}

			/// <summary>
			/// Force an APEX Actor to use a certian physical Lod.
			/// </summary>
			void ForcePhysicalLod(float lod);
			
			/// <summary>
			/// Ensure that all module - cached data is cached.
			/// </summary>
			void CacheModuleData();

			/// <summary>
			/// Selectively enables / disables debug visualization of a specific APEX actor.Default value it true.
			/// </summary>
			void SetEnableDebugVisualization(bool state);

		internal:
			property NxApexActor* UnmanagedPointer
			{
				NxApexActor* get();
			}
		};
	}
}