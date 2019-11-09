#pragma once

#include "Types.h"
#include "DataStructure.h"
#include "Mapper.h"
#include "TextureDescriptor.h"

namespace Safaga
{
	namespace Render
	{
		class Texture
		{
		public:
			Texture(TextureDescriptor _descriptor);

			void replaceRegion(PixelData _withPixelData);

			void bind();

			void unbind();

			std::string getName();

			int getTextureUnitIndex();

			unsigned int getId();

		private:
			unsigned int      mTextureId;
			TextureDescriptor mDescriptor;
			TextureUnit       mTextureUnit;
			static   int      mTextureUnitProvider;
		};
	}
}
