#include "Texture.h"

#include <stdint.h>
#include <math.h>
#include <algorithm>

#include <glad/glad.h>

namespace Platform
{
	namespace Render
	{
		int Texture::mTextureUnitProvider = 0;

		Texture::Texture(TextureDescriptor _descriptor)
		{
			mDescriptor = _descriptor;

			for (const auto& ele : TextureUnitMapper)
			{
				if (ele.second.second == mTextureUnitProvider)
				{
					mTextureUnit = ele.first;
					break;
				}
			}

			mTextureUnitProvider++;
			glGenTextures(1, &mTextureId);
			// int mipmapLevel = floor(log2(std::max(_descriptor.width, _descriptor.height)));
		}

		void Texture::replaceRegion(PixelData _withPixelData)
		{
			bind();

			switch (mDescriptor.type)
			{
			case TEXTURE_1D:
				glTexImage1D(GL_TEXTURE_1D, 0, PixelFormatMapper.at(mDescriptor.format), mDescriptor.region.size.width, 0,
					PixelFormatMapper.at(_withPixelData.format), DataTypeMapper.at(_withPixelData.type), _withPixelData.data);
				if (mDescriptor.mipmapped)
				{
					glGenerateMipmap(GL_TEXTURE_1D);
				}
				break;
			case TEXTURE_2D:
				glTexImage2D(GL_TEXTURE_2D, 0, PixelFormatMapper.at(mDescriptor.format), mDescriptor.region.size.width, mDescriptor.region.size.height, 0,
					PixelFormatMapper.at(_withPixelData.format), DataTypeMapper.at(_withPixelData.type), _withPixelData.data);
				if (mDescriptor.mipmapped)
				{
					glGenerateMipmap(GL_TEXTURE_2D);
				}
				break;
			case TEXTURE_3D:
				glTexImage3D(GL_TEXTURE_3D, 0, PixelFormatMapper.at(mDescriptor.format), mDescriptor.region.size.width, mDescriptor.region.size.height,
					mDescriptor.region.size.depth, 0, PixelFormatMapper.at(_withPixelData.format), DataTypeMapper.at(_withPixelData.type), _withPixelData.data);

				if (mDescriptor.mipmapped)
				{
					glGenerateMipmap(GL_TEXTURE_3D);
				}
				break;
			default:
				break;
			}
			unbind();
		}

		void Texture::bind()
		{
			glActiveTexture(TextureUnitMapper.at(mTextureUnit).first);
			glBindTexture(TextureTypeMapper.at(mDescriptor.type), mTextureId);
		}

		void Texture::unbind()
		{
			glBindTexture(TextureTypeMapper.at(mDescriptor.type), 0);
		}

		std::string Texture::getName()
		{
			return mDescriptor.name;
		}

		int Texture::getTextureUnitIndex()
		{
			return TextureUnitMapper.at(mTextureUnit).second;
		}

		unsigned int Texture::getId()
		{
			return mTextureId;
		}
	}
}