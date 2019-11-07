#pragma once

#include <vector>

#include <glad/glad.h>

#include "DataStructure.h"
#include "VertexDescriptor.h"

namespace Platform
{
	namespace Render
	{
		class VertexBuffer
		{
		public:
			VertexBuffer(VertexDescriptor _descriptor, const std::vector<std::vector<float>>& _verticesList,
				const std::vector<unsigned int>& _indices = std::vector<unsigned int>());

			void bind();

			void unbind();

			~VertexBuffer();

		private:
			std::vector<unsigned int> mVBO;
			unsigned int mEBO, mVAO;
		};
	}
}
