#pragma once

namespace PhysX
{
	namespace Apex
	{
		public ref class ApexException : public Exception
		{
			internal:
				ApexException(String^ message)
					: Exception(message)
				{
					
				}
				
				ApexException(String^ format, ... array<Object^>^ args)
					: Exception(String::Format(format, args))
				{
					
				}
		};
	};
};