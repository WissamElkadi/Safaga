#include "SamplerNode.h"
#include <Device.h>

namespace Safaga
{
	namespace Core
	{
		SamplerNode::SamplerNode(Render::SamplerDescriptor _descriptor)
		{
			mSampler = Render::Device::make_shared<Render::Sampler>(_descriptor);
		}

		void SamplerNode::accept(INodeVisitor& _nodeVisitor)
		{
			_nodeVisitor.visit(*this);
		}
	}
}
