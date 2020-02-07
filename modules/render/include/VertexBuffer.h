#pragma once

#include <vector>

#include <glad/glad.h>

#include "DataStructure.h"
#include "VertexDescriptor.h"

namespace Safaga
{
	namespace Render
	{
		class VertexBuffer
		{
		public:
			void bind();

			void unbind();

			size_t getIndicesCount();
			size_t getVerticesCount();

			~VertexBuffer();

		private:
			std::vector<unsigned int> mVBO;
			unsigned int mEBO, mVAO;
			int mIndicesCount, mVerticesCount;

			VertexBuffer(VertexDescriptor& _descriptor, const std::vector<std::vector<float>>& _verticesList,
				const std::vector<unsigned int>& _indices = std::vector<unsigned int>());

			friend class Device;
			friend class std::_Ref_count_obj<VertexBuffer>;
		};
	}
}
