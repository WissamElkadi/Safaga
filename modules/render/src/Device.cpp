#include "Device.h"

#include "CommandQueue.h"

namespace Safaga
{
	namespace Render
	{
		std::shared_ptr<CommandQueue> Device::mCommandQueue = std::make_shared<CommandQueue>();

		int Device::getMaxVertexAttributes()
		{
			int maxVertexAttributes;
			glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &maxVertexAttributes);
			return maxVertexAttributes;
		}
	}
}
