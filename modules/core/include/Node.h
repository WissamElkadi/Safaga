#pragma once

#include <vector>
#include <memory>

#include "INodeVisitor.h"

namespace Safaga
{
	namespace Core
	{
		class Node : public std::enable_shared_from_this<Node>
		{
		public:
			virtual void accept(INodeVisitor& _nodeVisitor) = 0;
			virtual void traverse(INodeVisitor& _nodeVisitor) {};

			void addParent(std::shared_ptr<Node> _parentNode);

			virtual ~Node() = 0;
		private:
			std::vector<std::weak_ptr<Node>> mParents;
		};
	}
}
