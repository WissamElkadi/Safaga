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
			std::vector<float> getVertices();
			std::vector<unsigned int> getIndcies();

		private:
			std::vector<float>        mVertices;
			std::vector<unsigned int> mIndcies;
		};
	}
}
