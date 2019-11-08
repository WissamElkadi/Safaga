#pragma once

#include <vector>

#include <glad/glad.h>

#include "DataStructure.h"
#include "VertexDescriptor.h"

namespace Render
{
	class VertexBuffer
	{
	public:
		VertexBuffer(VertexDescriptor _descriptor, const std::vector<std::vector<float>>& _verticesList,
			const std::vector<unsigned int>& _indices = std::vector<unsigned int>());

		void bind();

		void unbind();

		size_t getIndicesCount();

		~VertexBuffer();

	private:
		std::vector<unsigned int> mVBO;
		unsigned int mEBO, mVAO;
		int mIndicesCount;
	};
}

