#pragma once

#include <GroupNode.h>

namespace Safaga
{
	namespace Core
	{
		class Scene
		{
		public:
			void addRootNode(std::shared_ptr<GroupNode> _rootNode);

		private:
			std::shared_ptr<GroupNode> mRootNode;
		};
	}
}
