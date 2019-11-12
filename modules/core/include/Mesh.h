#pragma once

#include "Node.h"

namespace Safaga
{
	namespace Core
	{
		class Mesh
		{
		public:
			Mesh(std::vector<float>& _vertices, std::vector<unsigned int>& _indcies);
			float* getVertices();
			unsigned int* getIndcies();

		private:
			std::vector<float>        mVertices;
			std::vector<unsigned int> mIndcies;
		};
	}
}
