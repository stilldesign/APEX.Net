#pragma once

#include "Module.h"
#include "UserAllocatorCallback.h"
#include "UserErrorCallback.h"
#include "SerializationEnum.h"

namespace PhysX
{
	namespace Apex
	{
		ref class ApexSceneDesc;
		ref class ApexScene;
		ref class ApexBoxShape;
		ref class Serializer;
		ref class Asset;

		public ref class ApexSdk : IDisposable
		{
		public:
			/// <summary>Raised before any disposing is performed.</summary>
			virtual event EventHandler^ OnDisposing;
			/// <summary>Raised once all disposing is performed.</summary>
			virtual event EventHandler^ OnDisposed;

		private:
			NxApexSDK* _apexSdk;
		public:
			ApexSdk(PhysX::Physics^ physics);
			~ApexSdk();
		protected:
			!ApexSdk();

		public:
			property bool Disposed
			{
				virtual bool get();
			}

			//

			generic<typename T> where T : Modules::Module, gcnew()
				T CreateModule();

			ApexScene^ CreateScene(ApexSceneDesc^ desc);

			ApexBoxShape^ CreateBoxShape([Optional] Nullable<Vector3> size);

			SerializeType GetSerializerType(array<Byte>^ peekData);

			Serializer^ CreateSerializer(SerializeType serializeType, ApexScene^ scene);

			Asset^ CreateAsset(Interface^ i, String^ name);

			/// <summary>
			/// Gets the PhysX SDK.
			/// </summary>
			property PhysX::Physics^ PhysXSdk
			{
				PhysX::Physics^ get();
			}

		internal:
			property NxApexSDK* UnmanagedPointer
			{
				NxApexSDK* get();
			}
		};
	};
};