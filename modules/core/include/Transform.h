#pragma once

#include "Node.h"
#include "MathUtils.h"

namespace Safaga
{
	namespace Core
	{
		class Transform : public Node
		{
		public:
			Transform(MathUtils::mat4& _matrix);
			void accept(INodeVisitor& _nodeVisitor) override;
			MathUtils::mat4 getMatrix();

		private:
			MathUtils::mat4 mMatrix;
		};
	}
}
