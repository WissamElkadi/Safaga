#pragma once

#include <string>

#include "Node.h"

#include <Types.h>
#include <Texture.h>

namespace Safaga
{
	namespace Core
	{
		class TextureNode : public Node
		{
		public:
			TextureNode(std::string& _name, TextureType _type, unsigned char* _buffer,
				uint32_t width, uint32_t _height, uint8_t _channel, PixelFormat _format);

			void accept(INodeVisitor& _nodeVisitor) override;

		private:
			std::string mName;
			TextureType mType;
			PixelFormat mFormat;
			uint32_t    mWidth;
			uint32_t    mHeight;
			uint8_t     mChannel;

			std::unique_ptr<Render::Texture> mTexture;

			void setupTexture(unsigned char* _buffer);
		};
	}
}
