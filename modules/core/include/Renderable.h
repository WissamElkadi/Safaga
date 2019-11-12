#pragma once

#include "Node.h"

namespace Safaga
{
	namespace Core
	{
		class Renderable : public Node
		{
		public:
			virtual void accept(INodeVisitor& _nodeVisitor);

		private:
		};
	}
}
