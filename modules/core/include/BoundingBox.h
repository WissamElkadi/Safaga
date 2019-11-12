#pragma once

#include "MathUtils.h"

namespace Safaga
{
	namespace Core
	{
		class BoundingBox
		{
		public:
			BoundingBox(MathUtils::vec3& _minPoint, MathUtils::vec3& _maxPoint);
			MathUtils::vec3 getMinPoint();
			MathUtils::vec3 getMaxPoint();

		private:
			MathUtils::vec3 mMinPoint;
			MathUtils::vec3 mMaxPoint;
		};
	}
}
