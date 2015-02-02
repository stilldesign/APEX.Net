#pragma once

#include "Parameter.h"

namespace PhysX
{
namespace Apex
{
	ref class ApexSdk;
	ref class Interface;

	namespace Modules
	{
		public ref class Module abstract : IDisposable
		{
		public:
			/// <summary>Raised before any disposing is performed.</summary>
			virtual event EventHandler^ OnDisposing;
			/// <summary>Raised once all disposing is performed.</summary>
			virtual event EventHandler^ OnDisposed;

		private:
			NxModule* _module;
			ApexSdk^ _owner;

		protected:
			Module();
		public:
			~Module();
		protected:
			!Module();

		public:
			property bool Disposed
			{
				virtual bool get();
			}

		internal:
			void Init(NxModule* module, ApexSdk^ owner);

		public:
			void Initalize(Interface^ i);

			array<ApexParameter^>^ GetParameters();

			Interface^ GetDefaultModuleDesc();

			void SetInterfaceValue(int parameterIndex, int value);

			//

			property String^ Name
			{
				String^ get();
			}

			property int ModuleId
			{
				int get();
			}

			property float LodBenefitWeight
			{
				float get();
				void set(float value);
			}

		internal:
			property NxModule* UnmanagedPointer
			{
				NxModule* get();
			}
		};
	};
};
};