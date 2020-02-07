#pragma once

#include "DepthDescriptor.h"
#include "StencilDescriptor.h"

namespace Safaga
{
	namespace Render
	{
		class DepthStencilState
		{
		public:
			DepthStencilState(DepthDescriptor& _depthDescriptor, StencilDescriptor& _stencilDescriptor);

		private:
			DepthDescriptor mDepthDescriptor;
			StencilDescriptor mStencilDescriptor;
		};
	}
}