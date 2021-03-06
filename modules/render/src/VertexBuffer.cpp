#include "VertexBuffer.h"

#include <glad/glad.h>

#include "Mapper.h"

namespace Safaga
{
	namespace Render
	{
		VertexBuffer::VertexBuffer(VertexDescriptor _descriptor, const std::vector<std::vector<float>>& _verticesList, const std::vector<unsigned int>& _indices)
		{
			glGenVertexArrays(1, &mVAO);
			mVBO.resize(_verticesList.size());
			glGenBuffers(_verticesList.size(), mVBO.data());

			glGenBuffers(1, &mEBO);

			// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
			glBindVertexArray(mVAO);

			mVerticesCount = _verticesList.at(0).size() / _descriptor.layouts[0].stride * sizeof(float);

			for (int i = 0; i < _verticesList.size(); ++i)
			{
				glBindBuffer(GL_ARRAY_BUFFER, mVBO.at(i));
				glBufferData(GL_ARRAY_BUFFER, _verticesList.at(i).size() * sizeof(float), _verticesList.at(i).data(), GL_STATIC_DRAW);
			}

			if (!_indices.empty())
			{
				mIndicesCount = _indices.size();
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO);
				glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indices.size() * sizeof(unsigned int), _indices.data(), GL_STATIC_DRAW);
			}

			for (int i = 0; i < _descriptor.attributes.size(); ++i)
			{
				auto attribute = _descriptor.attributes.at(i);
				auto layout = _descriptor.layouts.at(attribute.bufferIndex);

				//glBindBuffer(GL_ARRAY_BUFFER, mVBO.at(attribute.bufferIndex));

				// position attribute
				//int attributePosition = glGetAttribLocation(programID, attribute.name);
				glVertexAttribPointer(i, 3, TypeMapper.at(attribute.type), attribute.normalized, layout.stride, (void*)attribute.offset);
				glEnableVertexAttribArray(i);
			}

			glEnableVertexAttribArray(0);

			// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
			glBindBuffer(GL_ARRAY_BUFFER, 0);

			// remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
			//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

			// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
			// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
			glBindVertexArray(0);
		}


		void VertexBuffer::bind()
		{
			glBindVertexArray(mVAO);
		}

		void VertexBuffer::unbind()
		{
			glBindVertexArray(0);
		}

		size_t VertexBuffer::getIndicesCount()
		{
			return mIndicesCount;
		}

		size_t VertexBuffer::getVerticesCount()
		{
			return mVerticesCount;
		}

		VertexBuffer::~VertexBuffer()
		{
			glDeleteVertexArrays(1, &mVAO);

			for (auto vbo : mVBO)
				glDeleteBuffers(1, &vbo);

			glDeleteBuffers(1, &mEBO);
		}
	}
}
