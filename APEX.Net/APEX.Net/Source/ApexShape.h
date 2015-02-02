#pragma once

namespace PhysX
{
	namespace Apex
	{
		ref class Physics;
		ref class ApexSdk;

		public ref class ApexShape abstract : IDisposable
		{
		public:
			/// <summary>Raised before any disposing is performed.</summary>
			virtual event EventHandler^ OnDisposing;
			/// <summary>Raised once all disposing is performed.</summary>
			virtual event EventHandler^ OnDisposed;

		private:
			NxApexShape* _shape;
			ApexSdk^ _apexSdk;

		protected:
			ApexShape(NxApexShape* shape, PhysX::Apex::ApexSdk^ apexSdk);
		public:
			~ApexShape();
		protected:
			!ApexShape();

		public:
			property bool Disposed
			{
				virtual bool get();
			}

			bool IntersectAgainstAABB(Bounds3 bounds);

			Bounds3 GetAABB();

			/// <summary>
			/// Gets the PhysX SDK this shape was created in.
			/// </summary>
			property Apex::ApexSdk^ ApexSdk
			{
				Apex::ApexSdk^ get();
			}

			property Matrix Pose
			{
				Matrix get();
				void set(Matrix value);
			}

			property Matrix PreviousPose
			{
				Matrix get();
			}

		internal:
			property NxApexShape* UnmanagedPointer
			{
				NxApexShape* get();
			}
		};
	};
};