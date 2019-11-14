#pragma once

#include "LightNode.h"

namespace Safaga
{
	namespace Core
	{
		class PointLight : public LightNode
		{
		public:
			void accept(INodeVisitor& _nodeVisitor) override;
		};
	}
}
