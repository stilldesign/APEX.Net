#pragma once

namespace PhysX
{
	namespace Apex
	{
		ref class ApexSdk;

		public ref class Interface : IDisposable
		{
			public:
				/// <summary>Raised before any disposing is performed.</summary>
				virtual event EventHandler^ OnDisposing;
				/// <summary>Raised once all disposing is performed.</summary>
				virtual event EventHandler^ OnDisposed;

			private:
				NxParameterized::Interface* _interface;

			internal:
				Interface(NxParameterized::Interface* i, ApexSdk^ owner);
			public:
				~Interface();
			protected:
				!Interface();
			public:
				property bool Disposed
				{
					virtual bool get();
				}

			public:
				void InitalizeToDefaults();

				array<int>^ Checksum(int bits);

				//

				property String^ ClassName
				{
					String^ get();
					void set(String^ value);
				}

				property String^ Name
				{
					String^ get();
					void set(String^ value);
				}

				property int Version
				{
					int get();
				}

				property int NumberOfParameters
				{
					int get();
				}

			internal:
				property NxParameterized::Interface* UnmanagedPointer
				{
					NxParameterized::Interface* get();
				}
		};
	};
};