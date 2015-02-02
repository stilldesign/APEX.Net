#pragma once

#define RangeToNxRange(range) (NxRange(range.Minimum, range.Maximum);)

namespace PhysX
{
	namespace Apex
	{
		generic<typename T> where T : value class
		public value class Range
		{
			public:
				Range(T min, T max)
				{
					Minimum = min;
					Maximum = max;
				}

			public:
				//static bool operator ==(Range^ range0, Range^ range1);

				property T Minimum;
				property T Maximum;
		};
	};
};