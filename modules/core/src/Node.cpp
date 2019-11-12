#include "Node.h"

namespace Safaga
{
	namespace Core
	{
		void Node::addParent(std::shared_ptr<Node> _parentNode)
		{
			mParents.push_back(_parentNode);
		}
	}
}
