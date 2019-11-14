#include "SwitchNode.h"

namespace Safaga
{
	namespace Core
	{
		void SwitchNode::accept(INodeVisitor& _nodeVisitor)
		{
			_nodeVisitor.visit(*this);
		}
	}
}
