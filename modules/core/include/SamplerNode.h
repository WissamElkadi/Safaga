#pragma once

#include "Node.h"

#include <Sampler.h>

namespace Safaga
{
	namespace Core
	{
		class SamplerNode : public Node
		{
		public:
			SamplerNode(Render::SamplerDescriptor _descriptor);
			void accept(INodeVisitor& _nodeVisitor) override;

		private:
			std::unique_ptr<Render::Sampler>   mSampler;
		};
	}
}
