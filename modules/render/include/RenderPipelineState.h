#pragma once

#include <memory>

#include "Shader.h"
#include "RenderPieplineDescriptor.h"
#include "Texture.h"
#include "Sampler.h"

namespace Platform
{
	namespace Render
	{
		class RenderPipelineState
		{
		public:

			RenderPipelineState(RenderPieplineDescriptor* _renderPieplineDescriptor);

			void link();

			void use();

			void unuse();

			int getId();

		private:
			int mShaderProgramId;
			bool mLinked = false;
			RenderPieplineDescriptor* mRenderPieplineDescriptor;

			void updateTextures();
		};
	}
}