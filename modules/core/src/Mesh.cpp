#include "Mesh.h"

namespace Safaga
{
	namespace Core
	{
		Mesh::Mesh(std::vector<float>& _vertices, std::vector<unsigned int>& _indcies) :
			mVertices(_vertices), mIndcies(_indcies)
		{
		}

		std::vector<float> Mesh::getVertices()
		{
			return mVertices;
		}

		std::vector<unsigned int> Mesh::getIndcies()
		{
			return mIndcies;
		}
	}
}
