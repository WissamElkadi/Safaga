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
			void link();

			void use();

			void unuse();

			int getId();

		private:
			int mShaderProgramId;
			bool mLinked = false;
			RenderPieplineDescriptor mRenderPieplineDescriptor;

			RenderPipelineState(RenderPieplineDescriptor& _renderPieplineDescriptor);
			void updateTextures();

			friend class Device;
			friend class std::_Ref_count_obj<RenderPipelineState>;
		};
	}
}
