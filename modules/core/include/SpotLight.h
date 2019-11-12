#pragma once

#include "Light.h"


namespace Safaga
{
	namespace Core
	{
		class SpotLight : public Light
		{
		public:
			void accept(INodeVisitor& _nodeVisitor) override;
		};
	}
}
