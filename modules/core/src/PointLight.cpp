#include "PointLight.h"

namespace Safaga
{
	namespace Core
	{
		void PointLight::accept(INodeVisitor& _nodeVisitor)
		{
			_nodeVisitor.visit(*this);
		}
	}
}
