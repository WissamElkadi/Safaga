#include "RenderCommandEncoder.h"

namespace Safaga
{
	namespace Render
	{
		RenderCommandEncoder::RenderCommandEncoder(RenderPassDescriptor& _renderPassDescriptor)
		{
			mRenderPassDescriptor = _renderPassDescriptor;
		}

		void RenderCommandEncoder::drawElements(DrawingPrimitive _drawingPrimitive, Type _type)
		{
			glDrawElements(DrawingPrimitiveMapper.at(_drawingPrimitive), mVertexBuffer->getIndicesCount(), TypeMapper.at(_type), 0);
		}

		void RenderCommandEncoder::begin()
		{
			glClearColor(mColor.r, mColor.g, mColor.b, mColor.a);
			glClear(mClearBufferBits);

			mRenderPipelineState->use();
			mVertexBuffer->bind();
		}

		void RenderCommandEncoder::draw(DrawingPrimitive _drawingPrimitive)
		{
			for (const auto& uniformBuffer : mUniformBuffers)
			{
				uniformBuffer->update(mRenderPipelineState->getId());
			}

			glDrawArrays(DrawingPrimitiveMapper.at(_drawingPrimitive), 0, mVertexBuffer->getVerticesCount());
		}

		void RenderCommandEncoder::endEncoding()
		{
			mVertexBuffer->unbind();
			mRenderPipelineState->unuse();
		}

		void RenderCommandEncoder::setClearColor(Color _color)
		{
			mClearBufferBits |= GL_COLOR_BUFFER_BIT;
			mColor = _color;
		}

		void RenderCommandEncoder::setRenderPipelineState(std::shared_ptr<RenderPipelineState> _RenderPipelineState)
		{
			mRenderPipelineState = _RenderPipelineState;
			mRenderPipelineState->link();
		}

		void RenderCommandEncoder::setFillMode(Face _face, FillMode _fillMode)
		{
			glPolygonMode(FaceMapper.at(_face), FillModeMapper.at(_fillMode));
		}

		void RenderCommandEncoder::setFrontFacingWinding(Winding _winding)
		{
			glFrontFace(WindingMapper.at(_winding));
		}

		void RenderCommandEncoder::setCullMode(CullMode _cullMode)
		{
			glCullFace(CullModeMapper.at(_cullMode));
		}

		void RenderCommandEncoder::setDepthDescriptor(DepthDescriptor _depthDescriptor)
		{
			if (_depthDescriptor.depthWriteEnabled)
			{
				mClearBufferBits |= GL_DEPTH_BUFFER_BIT;
				glEnable(GL_DEPTH_TEST);
				glDepthFunc(CompareFunctionMapper.at(_depthDescriptor.depthCompareFunction));
			}
		}

		void RenderCommandEncoder::setStencilDescriptor(StencilDescriptor _stencilDescriptor)
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

		void RenderCommandEncoder::setViewPort(ViewPort _viewPort)
		{
			glViewport(_viewPort.originX, _viewPort.originY, _viewPort.width, _viewPort.height);
		}

		void RenderCommandEncoder::setViewports(std::vector<ViewPort>& _viewPorts)
		{

		}
		void RenderCommandEncoder::setScissorRect(ScissorRect _scissorRect)
		{

		}
		void RenderCommandEncoder::setScissorRects(std::vector<ScissorRect>& _scissorRects)
		{

		}
		void RenderCommandEncoder::setBlendColor(Color _color)
		{

		}
		void RenderCommandEncoder::setVisibilityResultMode(VisibilityResultMode _visibilityResultMode, int offset)
		{

		}

		void RenderCommandEncoder::setUniformBuffers(std::vector<std::shared_ptr<UniformBuffer>>& _uniformBuffers)
		{
			mUniformBuffers = _uniformBuffers;
		}

		void RenderCommandEncoder::setVertexBuffer(std::shared_ptr<VertexBuffer> _vertexBuffer)
		{
			mVertexBuffer = _vertexBuffer;
		}
	}
}
