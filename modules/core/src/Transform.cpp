#include "Transform.h"

namespace Safaga
{
	namespace Core
	{
		Transform::Transform(MathUtils::mat4& _matrix) :
			mMatrix(_matrix)
		{
		}

		void Transform::accept(INodeVisitor& _nodeVisitor)
		{
			_nodeVisitor.visit(*this);
		}

		MathUtils::mat4 Transform::getMatrix()
		{
			return mMatrix;
		}
	}
}
