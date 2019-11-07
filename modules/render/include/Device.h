#pragma once

#include <memory>

#include "RenderPipelineState.h"
#include "RenderPieplineDescriptor.h"

namespace Platform {
	namespace Render
	{
		class Device
		{
		public:
			static int getMaxVertexAttributes();

			static std::unique_ptr<RenderPipelineState> makeRenderPipelineState(RenderPieplineDescriptor* _renderPieplineDescriptor);
		};
	}
}
