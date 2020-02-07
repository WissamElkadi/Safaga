#include "DepthStencilState.h"

namespace Safaga
{
	namespace Render
	{
		DepthStencilState::DepthStencilState(DepthDescriptor& _depthDescriptor, StencilDescriptor& _stencilDescriptor) :
			mDepthDescriptor(_depthDescriptor), mStencilDescriptor(_stencilDescriptor)
		{
		}
	}
}
