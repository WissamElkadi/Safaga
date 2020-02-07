#include "Sampler.h"

#include <glad/glad.h>

namespace Safaga
{
	namespace Render
	{

		Sampler::Sampler(SamplerDescriptor& _descriptor)
		{
			mSamplerDescriptor = _descriptor;
		}

		void Sampler::bind()
		{
			// Texture Wrapping
			glTexParameteri(TextureTypeMapper.at(mSamplerDescriptor.textureType), GL_TEXTURE_WRAP_S, TextureWrapMapper.at(mSamplerDescriptor.sWrap));
			if (mSamplerDescriptor.textureType == TextureType::TEXTURE_2D)
				glTexParameteri(TextureTypeMapper.at(mSamplerDescriptor.textureType), GL_TEXTURE_WRAP_T, TextureWrapMapper.at(mSamplerDescriptor.tWrap));
			if (mSamplerDescriptor.textureType == TextureType::TEXTURE_3D)
				glTexParameteri(TextureTypeMapper.at(mSamplerDescriptor.textureType), GL_TEXTURE_WRAP_R, TextureWrapMapper.at(mSamplerDescriptor.rWrap));

			if (mSamplerDescriptor.tWrap == TextureWrap::CLAMP_TO_EDGE ||
				mSamplerDescriptor.sWrap == TextureWrap::CLAMP_TO_EDGE ||
				mSamplerDescriptor.rWrap == TextureWrap::CLAMP_TO_EDGE)
			{
				// Border Color
				glTexParameterfv(TextureTypeMapper.at(mSamplerDescriptor.textureType), GL_TEXTURE_BORDER_COLOR, mSamplerDescriptor.borderColor.data());
			}

			// Texture Filtering
			glTexParameteri(TextureTypeMapper.at(mSamplerDescriptor.textureType), GL_TEXTURE_MIN_FILTER, TextureFilterMapper.at(mSamplerDescriptor.minFilter));
			glTexParameteri(TextureTypeMapper.at(mSamplerDescriptor.textureType), GL_TEXTURE_MAG_FILTER, TextureFilterMapper.at(mSamplerDescriptor.magFilter));
		}
	}
}
