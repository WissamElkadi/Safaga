#include "SamplerNode.h"

namespace Safaga
{
	namespace Core
	{
		SamplerNode::SamplerNode(Render::SamplerDescriptor _descriptor)
		{
			mSampler = std::make_unique<Render::Sampler>(_descriptor);
		}

		void SamplerNode::accept(INodeVisitor& _nodeVisitor)
		{
			_nodeVisitor.visit(*this);
		}
	}
}
