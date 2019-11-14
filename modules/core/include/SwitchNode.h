#pragma once

#include "Node.h"

namespace Safaga
{
	namespace Core
	{
		class SwitchNode : public Node
		{
		public:
			void accept(INodeVisitor& _nodeVisitor) override;
		};
	}
}
