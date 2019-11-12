#pragma once

#include "Light.h"

namespace Safaga
{
	namespace Core
	{
		class DirectionalLight : public Light
		{
		public:
			DirectionalLight(MathUtils::vec3 _position, MathUtils::vec3 _direction, MathUtils::vec3 _color = MathUtils::vec3(1.0f));

			void accept(INodeVisitor& _nodeVisitor) override;

		private:
			MathUtils::vec3 mDirection;
		};
	}
}
