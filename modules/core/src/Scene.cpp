#include "Scene.h"

namespace Safaga
{
	namespace Core
	{
		void Scene::addRootNode(std::shared_ptr<GroupNode> _rootNode)
		{
			mRootNode = _rootNode;
		}
	}
}
