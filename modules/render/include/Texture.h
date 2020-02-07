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
			void replaceRegion(PixelData _withPixelData);

			void bind();

			void unbind();

			std::string getName();

			int getTextureUnitIndex();

			unsigned int getId();

		private:
			Texture(TextureDescriptor& _descriptor);

			unsigned int      mTextureId;
			TextureDescriptor mDescriptor;
			TextureUnit       mTextureUnit;
			static   int      mTextureUnitProvider;

			friend class Device;
			friend class std::_Ref_count_obj<Texture>;
		};
	}
}
