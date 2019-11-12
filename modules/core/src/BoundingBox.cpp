#include "BoundingBox.h"

namespace Safaga
{
	namespace Core
	{
		BoundingBox::BoundingBox(MathUtils::vec3& _minPoint, MathUtils::vec3& _maxPoint) :
			mMinPoint(_minPoint), mMaxPoint(_maxPoint)
		{
		}

		MathUtils::vec3 BoundingBox::getMinPoint()
		{
			return mMinPoint;
		}

		MathUtils::vec3 BoundingBox::getMaxPoint()
		{
			return mMaxPoint;
		}
	}
}
