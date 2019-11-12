#pragma once

#include "Node.h"

namespace Safaga
{
	namespace Core
	{
		class Group : public Node
		{
		public:
			void accept(INodeVisitor& _nodeVisitor) override;
			void traverse(INodeVisitor& _nodeVisitor) override;

			// Group Child List Operation
			bool contains(std::shared_ptr<Node> _node) const;
			bool addChild(std::shared_ptr<Node> _childNode);
			bool insertChild(size_t _index, std::shared_ptr<Node> _childNode);
			bool removeChild(std::shared_ptr<Node> _childNode);
			bool replaceChild(std::shared_ptr<Node> _originalNode, std::shared_ptr<Node> _newChild);

			inline std::shared_ptr<Node> getChild(size_t _index);

		private:
			std::vector<std::shared_ptr<Node>> mChildren;

			size_t getChildIndex(std::shared_ptr<Node> _childNode) const;
		};
	}
}
