#pragma once

#include <memory>

#include "RenderPipelineState.h"
#include "RenderPieplineDescriptor.h"

namespace Safaga
{
	namespace Render
	{
		class Device
		{
		public:
			static int getMaxVertexAttributes();

			static std::unique_ptr<RenderPipelineState> makeRenderPipelineState(std::unique_ptr<RenderPieplineDescriptor> _renderPieplineDescriptor);
		};
	}
}