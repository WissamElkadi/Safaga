#include "Switch.h"

namespace Safaga
{
	namespace Core
	{
		void Switch::accept(INodeVisitor& _nodeVisitor)
		{
			_nodeVisitor.visit(*this);
		}
	}
}
