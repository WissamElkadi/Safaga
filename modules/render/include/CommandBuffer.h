#pragma once

#include <memory>

#include "RenderCommandEncoder.h"
#include "RenderPassDescriptor.h"

namespace Safaga
{
	namespace Render
	{
		class CommandBuffer
		{
		public:
			std::shared_ptr<RenderCommandEncoder> makeRenderCommandEncoder(RenderPassDescriptor& _renderPassDescriptor);
			void commit();
		private:
		};
	}
}

