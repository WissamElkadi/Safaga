#pragma once

#include "Types.h"

namespace Safaga
{
	namespace Render
	{
		struct DepthDescriptor
		{
			bool     depthWriteEnabled   = { false };
			CompareFunction  depthCompareFunction;
			DepthDescriptor(bool _enable, CompareFunction _compareFunction) :
				depthWriteEnabled (_enable), depthCompareFunction(_compareFunction)
			{
			}
		};
	}
}
