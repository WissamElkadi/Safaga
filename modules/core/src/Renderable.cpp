#include "Renderable.h"

namespace Safaga
{
	namespace Core
	{
		void Renderable::accept(INodeVisitor& _nodeVisitor)
		{
			_nodeVisitor.visit(*this);
		}
	}
}
