#pragma once

#include "RenderPassAttachmentDescriptor.h"

namespace Safaga
{
	namespace Render
	{
		struct RenderPassDescriptor
		{
			std::vector<RenderPassAttachmentDescriptor> colorAttachments;
			RenderPassAttachmentDescriptor              depthAttachment;
			RenderPassAttachmentDescriptor              stencilAttachment;
		};
	}
}