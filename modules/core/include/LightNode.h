#pragma once

#include "Node.h"
#include "MathUtils.h"

namespace Safaga
{
	namespace Core
	{
		class LightNode : public Node
		{
		public:
			LightNode(MathUtils::vec3 _position, MathUtils::vec3 _color = MathUtils::vec3(1.0f));

		protected:
			MathUtils::vec3 mPosition;
			MathUtils::vec3 mColor;
		};
	}
}
