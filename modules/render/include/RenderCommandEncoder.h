#pragma once

#include "RenderPassDescriptor.h"
#include "DepthDescriptor.h"
#include "StencilDescriptor.h"
#include "VertexBuffer.h"
#include "RenderPipelineState.h"
#include "UniformBuffer.h"
#include "VertexDescriptor.h"
#include "Buffer.h"
#include "Sampler.h"
#include "Texture.h"

namespace Safaga
{
	namespace Render
	{
		class RenderCommandEncoder
		{
		public:
			RenderCommandEncoder(RenderPassDescriptor& _renderPassDescriptor);
			//Draw Commands
			void drawElements(DrawingPrimitive _drawingPrimitive, Type _type);

			void begin();
			void draw(DrawingPrimitive _drawingPrimitive);
			void endEncoding();

			// set Graphics Rendering Behavior
			void setClearColor(Color _color);
			void setRenderPipelineState(std::shared_ptr<RenderPipelineState> _RenderPipelineState);
			void setFillMode(Face _face, FillMode _fillMode);
			void setFrontFacingWinding(Winding _winding);
			void setCullMode(CullMode _cullMode);

			// Depth and Stencil Behavior
			void setDepthDescriptor(DepthDescriptor _despthDescriptor);
			void setStencilDescriptor(StencilDescriptor _stencilDescriptor);

			// Setting Viewport and Scissor Behavior
			void setViewPort(ViewPort _viewPort);
			void setViewports(std::vector<ViewPort>& _viewPorts);
			void setScissorRect(ScissorRect _scissorRect);
			void setScissorRects(std::vector<ScissorRect>& _scissorRects);

			// Setting Blend Behavior
			void setBlendColor(Color _color);

			//Setting Visibility Behavior
			void setVisibilityResultMode(VisibilityResultMode _visibilityResultMode, int _offset);

			// Setting Buffers
			void setUniformBuffers(std::vector<std::shared_ptr<UniformBuffer>>& _uniformBuffers);
			void setVertexBuffer(std::shared_ptr<VertexBuffer> _vertexBuffer);


		private:
			RenderPassDescriptor                          mRenderPassDescriptor;
			std::shared_ptr<RenderPipelineState>          mRenderPipelineState;
			std::shared_ptr<VertexBuffer>                 mVertexBuffer;
			std::vector<std::shared_ptr<UniformBuffer>>   mUniformBuffers;
			Buffer*                                       mIndexBuffer;
			Color                                         mColor;
			unsigned int                                  mClearBufferBits = 0;			
		};
	}
}

