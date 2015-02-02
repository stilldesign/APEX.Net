#pragma once

namespace PhysX
{
	namespace Apex
	{
		ref class ApexSdk;
		ref class Interface;
		ref class ApexScene;
		ref class ApexActor;

		public ref class Asset abstract : IDisposable
		{
		public:
			/// <summary>Raised before any disposing is performed.</summary>
			virtual event EventHandler^ OnDisposing;
			/// <summary>Raised once all disposing is performed.</summary>
			virtual event EventHandler^ OnDisposed;

		private:
			NxApexAsset* _asset;
			ApexSdk^ _apexSdk;

		protected:
			Asset(NxApexAsset* asset, ApexSdk^ owner);
		public:
			~Asset();
		protected:
			!Asset();

		public:
			property bool Disposed
			{
				virtual bool get();
			}

			/// <summary>
			/// 
			/// </summary>
			bool IsValidForCreation(Interface^ actorParameters, ApexScene^ scene);

			/// <summary>
			/// 
			/// </summary>
			Interface^ GetDefaultActorDesc();

			/// <summary>
			/// Creates an Actor representing the Asset in a Scene.
			/// </summary>
			ApexActor^ CreateApexActor(Interface^ actorParameters, ApexScene^ apexScene);

			/// <summary>
			/// Returns the name of this deserialized asset.
			/// </summary>
			property String^ Name
			{
				String^ get();
			}

			/// <summary>
			/// Returns the ID of the asset's authorable object type.
			/// </summary>
			property int ObjectTypeId
			{
				int get();
			}

			/// <summary>
			/// Returns the name of this asset's authorable object type.
			/// </summary>
			property String^ ObjectTypeName
			{
				String^ get();
			}

			/// <summary>
			/// Returns true if the parameterized object of the asset has been modified.
			/// </summary>
			property bool IsDirty
			{
				bool get();
			}

		internal:
			property NxApexAsset* UnmanagedPointer
			{
				NxApexAsset* get();
			}
		};
	}
}