#include "CommandBuffer.h"

namespace Safaga
{
	namespace Render
	{
		std::shared_ptr<RenderCommandEncoder> CommandBuffer:: makeRenderCommandEncoder(RenderPassDescriptor& _renderPassDescriptor)
		{
			return std::make_shared<RenderCommandEncoder>(_renderPassDescriptor);
		}
	}
}
