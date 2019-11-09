#include "Drawer.h"

namespace Safaga
{
	namespace Render
	{
		void Drawer::drawElements(DrawingPrimitive _drawingPrimitive, Type _type)
		{
			glClearColor(mColor.r, mColor.g, mColor.b, mColor.a);

			glClear(mClearBufferBits);

			mRenderPipelineState->use();
			mVertexBuffer->bind();

			for (const auto& uniformBuffer : mUniformBuffers)
			{
				uniformBuffer->update(mRenderPipelineState->getId());
			}

			glDrawElements(DrawingPrimitiveMapper.at(_drawingPrimitive), mVertexBuffer->getIndicesCount(), TypeMapper.at(_type), 0);

			mVertexBuffer->unbind();
			mRenderPipelineState->unuse();
		}

		void Drawer::draw(DrawingPrimitive _drawingPrimitive)
		{
			glClearColor(mColor.r, mColor.g, mColor.b, mColor.a);
			glClear(mClearBufferBits);

			mRenderPipelineState->use();
			mVertexBuffer->bind();

			for (const auto& uniformBuffer : mUniformBuffers)
			{
				uniformBuffer->update(mRenderPipelineState->getId());
			}

			glDrawArrays(DrawingPrimitiveMapper.at(_drawingPrimitive), 0, mVertexBuffer->getVerticesCount());

			mVertexBuffer->unbind();
			mRenderPipelineState->unuse();
		}

		void Drawer::setClearColor(Color _color)
		{
			mClearBufferBits |= GL_COLOR_BUFFER_BIT;
			mColor = _color;
		}

		void Drawer::setRenderPipelineState(RenderPipelineState* _RenderPipelineState)
		{
			mRenderPipelineState = _RenderPipelineState;
			mRenderPipelineState->link();
		}

		void Drawer::setFillMode(Face _face, FillMode _fillMode)
		{
			glPolygonMode(FaceMapper.at(_face), FillModeMapper.at(_fillMode));
		}

		void Drawer::setFrontFacingWinding(Winding _winding)
		{
			glFrontFace(WindingMapper.at(_winding));
		}

		void Drawer::setCullMode(CullMode _cullMode)
		{
			glCullFace(CullModeMapper.at(_cullMode));
		}

		void Drawer::setDepthDescriptor(DepthDescriptor _depthDescriptor)
		{
			if (_depthDescriptor.depthWriteEnabled)
			{
				mClearBufferBits |= GL_DEPTH_BUFFER_BIT;
				glEnable(GL_DEPTH_TEST);
				glDepthFunc(CompareFunctionMapper.at(_depthDescriptor.depthCompareFunction));
			}
		}

		void Drawer::setStencilDescriptor(StencilDescriptor _stencilDescriptor)
		{
			if (_stencilDescriptor.stencilWriteEnabled)
			{
				mClearBufferBits |= GL_STENCIL_BUFFER_BIT;
				glEnable(GL_STENCIL_TEST);
				glStencilFunc(CompareFunctionMapper.at(_stencilDescriptor.stencilCompareFunction), _stencilDescriptor.refrenceValue, _stencilDescriptor.mask);
				glStencilOp(StencilOperationMapper.at(_stencilDescriptor.stencilFailureOperation), StencilOperationMapper.at(_stencilDescriptor.depthFailureOperation),
					        StencilOperationMapper.at(_stencilDescriptor.depthStencilPassOperation));
			}
		}

		void Drawer::setViewPort(ViewPort _viewPort)
		{
			glViewport(_viewPort.originX, _viewPort.originY, _viewPort.width, _viewPort.height);
		}

		void Drawer::setViewports(std::vector<ViewPort>& _viewPorts)
		{

		}
		void Drawer::setScissorRect(ScissorRect _scissorRect)
		{

		}
		void Drawer::setScissorRects(std::vector<ScissorRect>& _scissorRects)
		{

		}
		void Drawer::setBlendColor(Color _color)
		{

		}
		void Drawer::setVisibilityResultMode(VisibilityResultMode _visibilityResultMode, int offset)
		{

		}

		void Drawer::setUniformBuffers(std::vector<std::shared_ptr<UniformBuffer>>& _uniformBuffers)
		{
			mUniformBuffers = _uniformBuffers;
		}

		void Drawer::setVertexBuffer(VertexBuffer* _vertexBuffer)
		{
			mVertexBuffer = _vertexBuffer;
		}
	}
}
