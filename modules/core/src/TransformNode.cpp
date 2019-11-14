#include "TransformNode.h"

namespace Safaga
{
	namespace Core
	{
		TransformNode::TransformNode(MathUtils::mat4& _matrix) :
			mMatrix(_matrix)
		{
		}

		void TransformNode::accept(INodeVisitor& _nodeVisitor)
		{
			_nodeVisitor.visit(*this);
		}

		void TransformNode::setMatrix(MathUtils::mat4& _matrix)
		{
			mMatrix = _matrix;
		}

		MathUtils::mat4 TransformNode::getMatrix()
		{
			return mMatrix;
		}
	}
}
