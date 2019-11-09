#include "Device.h"

namespace Safaga
{
	namespace Render
	{
		int Device::getMaxVertexAttributes()
		{
			int maxVertexAttributes;
			glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &maxVertexAttributes);
			return maxVertexAttributes;
		}

		std::unique_ptr<RenderPipelineState> Device::makeRenderPipelineState(std::unique_ptr<RenderPieplineDescriptor> _renderPieplineDescriptor)
		{
			std::unique_ptr<RenderPipelineState> state = std::make_unique<RenderPipelineState>(_renderPieplineDescriptor);
			return std::move(state);
		}
	}
}
