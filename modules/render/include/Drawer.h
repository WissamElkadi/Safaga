#pragma once

#include "VertexBuffer.h"
#include "RenderPipelineState.h"
#include "UniformBuffer.h"
#include "VertexDescriptor.h"
#include "Buffer.h"
#include "Sampler.h"
#include "Texture.h"

namespace Render
{
	class Drawer
	{
	public:
		void drawElements(DrawingPrimitive _drawingPrimitive, Type _type);

		void draw(DrawingPrimitive _drawingPrimitive, int count);

		void setRenderPipelineState(RenderPipelineState* _RenderPipelineState);

		void setUniformBuffers(std::vector<std::shared_ptr<UniformBuffer>>& _uniformBuffers);

		void setViewPort(int _xOffset, int _yOffset, int _width, int _height);

		void setClearColor(Color _color);

		void setVertexBuffer(VertexBuffer* _vertexBuffer);

	private:
		RenderPipelineState*                          mRenderPipelineState;
		VertexBuffer*                                 mVertexBuffer;
		std::vector<std::shared_ptr<UniformBuffer>>   mUniformBuffers;
		Buffer*                                       mIndexBuffer;
		Color                                         mColor;
	};
}
