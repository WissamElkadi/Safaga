#pragma once

#include "Node.h"
#include "MathUtils.h"

namespace Safaga
{
	namespace Core
	{
		class TransformNode : public Node
		{
		public:
			TransformNode(MathUtils::mat4& _matrix = MathUtils::mat4(1.0));

			void accept(INodeVisitor& _nodeVisitor) override;

			void setMatrix(MathUtils::mat4& _matrix);
			MathUtils::mat4 getMatrix();

		private:
			MathUtils::mat4 mMatrix;
		};
	}
}
