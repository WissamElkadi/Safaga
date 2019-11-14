#include "DirectionalLight.h"

#include "INodeVisitor.h"

namespace Safaga
{
	namespace Core
	{
		DirectionalLight::DirectionalLight(MathUtils::vec3 _position, MathUtils::vec3 _direction, MathUtils::vec3 _color) :
			LightNode(_position, _color), mDirection(_direction)
		{
		}

		void DirectionalLight::accept(INodeVisitor& _nodeVisitor)
		{
			_nodeVisitor.visit(*this);
		}
	}
}
