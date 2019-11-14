#pragma once

#include "LightNode.h"


namespace Safaga
{
	namespace Core
	{
		class SpotLight : public LightNode
		{
		public:
			void accept(INodeVisitor& _nodeVisitor) override;
		};
	}
}
