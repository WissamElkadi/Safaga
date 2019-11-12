#pragma once

#include "Node.h"

namespace Safaga
{
	namespace Core
	{
		class Switch : public Node
		{
		public:
			void accept(INodeVisitor& _nodeVisitor) override;
		};
	}
}
