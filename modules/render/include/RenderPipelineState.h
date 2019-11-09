#pragma once

#include <memory>

#include "Shader.h"
#include "RenderPieplineDescriptor.h"
#include "Texture.h"
#include "Sampler.h"

namespace Safaga
{
	namespace Render
	{
		class RenderPipelineState
		{
		public:

			RenderPipelineState(std::unique_ptr<RenderPieplineDescriptor>& _renderPieplineDescriptor);

			void link();

			void use();

			void unuse();

			int getId();

		private:
			int mShaderProgramId;
			bool mLinked = false;
			std::unique_ptr<RenderPieplineDescriptor> mRenderPieplineDescriptor;

			void updateTextures();
		};
	}
}