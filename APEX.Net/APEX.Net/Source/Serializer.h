#pragma once

namespace PhysX
{
	namespace Apex
	{
		ref class ApexSdk;
		ref class Interface;

		public ref class Serializer : IDisposable
		{
		public:
			/// <summary>Raised before any disposing is performed.</summary>
			virtual event EventHandler^ OnDisposing;
			/// <summary>Raised once all disposing is performed.</summary>
			virtual event EventHandler^ OnDisposed;

		private:
			NxParameterized::Serializer* _serializer;
			ApexSdk^ _owner;

		internal:
			Serializer(NxParameterized::Serializer* serializer, ApexSdk^ owner);
		public:
			~Serializer();
		protected:
			!Serializer();

		public:
			property bool Disposed
			{
				virtual bool get();
			}

			array<Interface^>^ Deserialize(System::IO::Stream^ serializedDataStream);

		internal:
			property NxParameterized::Serializer* UnmanagedPointer
			{
				NxParameterized::Serializer* get();
			}
		};
	};
};