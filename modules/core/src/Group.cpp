#include "Group.h"

namespace Safaga
{
	namespace Core
	{
		void Group::accept(INodeVisitor& _nodeVisitor)
		{
			traverse(_nodeVisitor);
		}

		void Group::traverse(INodeVisitor& _nodeVisitor)
		{
			for (auto & child : mChildren)
			{
				child->accept(_nodeVisitor);
			}
		}

		bool Group::contains(std::shared_ptr<Node> _node) const
		{
			for (const auto& child : mChildren)
			{
				if (child == _node)
				{
					return true;
				}
			}
			return false;
		}

		bool Group::addChild(std::shared_ptr<Node> _childNode)
		{
			if (!_childNode) return false;

			if (contains(_childNode))
			{
				return false;
			}

			mChildren.push_back(_childNode);
			_childNode->addParent(shared_from_this());

			return true;
		}

		bool Group::insertChild(size_t _index, std::shared_ptr<Node> _childNode)
		{
			if (!_childNode) return false;

			if (contains(_childNode))
			{
				return false;
			}

			mChildren.insert(mChildren.begin() + _index, _childNode);

			_childNode->addParent(shared_from_this());

			return true;
		}

		bool Group::removeChild(std::shared_ptr<Node> _childNode)
		{
			auto index = getChildIndex(_childNode);
			if (index == -1)
			{
				return false;
			}

			mChildren.erase(mChildren.begin() + index);

			return true;
		}

		bool Group::replaceChild(std::shared_ptr<Node> _originalNode, std::shared_ptr<Node> _newChild)
		{
			if (_newChild == nullptr || _originalNode == _newChild)
			{
				return false;
			}

			auto index = getChildIndex(_originalNode);
			if (index == -1)
			{
				return false;
			}

			if (index < mChildren.size())
			{
				mChildren[index] = _newChild;
				_newChild->addParent(shared_from_this());

				return true;
			}

			return false;
		}

		std::shared_ptr<Node> Group::getChild(size_t _index)
		{
			if (_index < 0 || _index >= mChildren.size())
			{
				return nullptr;
			}

			return mChildren[_index];
		}

		size_t Group::getChildIndex(std::shared_ptr<Node> _childNode) const
		{
			for (size_t i = 0; i < mChildren.size(); ++i)
			{
				if (mChildren[i] == _childNode) return i;
			}
			return -1;
		}
	}
}
