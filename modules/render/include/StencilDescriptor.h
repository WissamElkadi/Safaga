#pragma once

#include "Types.h"

#include <stdint.h>

namespace Safaga
{
	namespace Render
	{
		struct StencilDescriptor
		{
			bool             stencilWriteEnabled        = { false };
			uint32_t         refrenceValue;
			uint32_t         mask;
			CompareFunction  stencilCompareFunction;
			StencilOperation stencilFailureOperation;
			StencilOperation depthFailureOperation;
			StencilOperation depthStencilPassOperation;
		};
	}
}
