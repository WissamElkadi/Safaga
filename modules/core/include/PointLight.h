#pragma once

#include "Light.h"

namespace Safaga
{
	namespace Core
	{
		class PointLight : public Light
		{
		public:
			void accept(INodeVisitor& _nodeVisitor) override;
		};
	}
}
