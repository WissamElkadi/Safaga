#include "SpotLight.h"

namespace Safaga
{
	namespace Core
	{
		void SpotLight::accept(INodeVisitor& _nodeVisitor)
		{
			_nodeVisitor.visit(*this);
		}
	}
}
