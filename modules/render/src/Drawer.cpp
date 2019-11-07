#include "Drawer.h"

namespace Platform
{
	namespace Render
	{
			void Drawer::drawElements(DrawingPrimitive _drawingPrimitive, Type _type, size_t count)
			{
				glClearColor(mColor.r, mColor.g, mColor.b, mColor.a);
				glClear(GL_COLOR_BUFFER_BIT);

				mRenderPipelineState->use();
				mVertexBuffer->bind();

				for (const auto& uniformBuffer : mUniformBuffers)
				{
					uniformBuffer->update(mRenderPipelineState->getId());
				}

				glDrawElements(DrawingPrimitiveMapper.at(_drawingPrimitive), count, TypeMapper.at(_type), 0);

				mVertexBuffer->unbind();
				mRenderPipelineState->unuse();
			}

			void Drawer::draw(DrawingPrimitive _drawingPrimitive, int count)
			{
				glDrawArrays(DrawingPrimitiveMapper.at(_drawingPrimitive), 0, count);
			}

			void Drawer::setRenderPipelineState(RenderPipelineState* _RenderPipelineState)
			{
				mRenderPipelineState = _RenderPipelineState;
				mRenderPipelineState->link();
			}

			void Drawer::setUniformBuffers(std::vector<UniformBuffer*>& _uniformBuffers)
			{
				mUniformBuffers = _uniformBuffers;
			}

			void Drawer::setViewPort(int _xOffset, int _yOffset, int _width, int _height)
			{
				glViewport(_xOffset, _yOffset, _width, _height);
			}

			void Drawer::setClearColor(Color _color)
			{
				mColor = _color;
			}

			void Drawer::setVertexBuffer(VertexBuffer* _vertexBuffer)
			{
				mVertexBuffer = _vertexBuffer;
			}

			void Drawer::setIndexBuffer(Buffer* _indexBuffer)
			{
			}
	}
}