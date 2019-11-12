#include "Mesh.h"

namespace Safaga
{
	namespace Core
	{
		Mesh::Mesh(std::vector<float>& _vertices, std::vector<unsigned int>& _indcies) :
			mVertices(_vertices), mIndcies(_indcies)
		{
		}

		float* Mesh::getVertices()
		{
			return mVertices.data();
		}

		unsigned int* Mesh::getIndcies()
		{
			return mIndcies.data();
		}
	}
}
