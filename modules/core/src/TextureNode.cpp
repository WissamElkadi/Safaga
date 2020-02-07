#include "TextureNode.h"

#include <TextureDescriptor.h>

#include <Device.h>

namespace Safaga
{
	namespace Core
	{
		TextureNode::TextureNode(std::string& _name, TextureType _type, unsigned char* _buffer,
			uint32_t _width, uint32_t _height, uint8_t _channel, PixelFormat _format) :
			mName(_name), mType(_type), mWidth(_width), mHeight(_height), mChannel(_channel), mFormat(_format)
		{
			setupTexture(_buffer);
		}

		void TextureNode::accept(INodeVisitor& _nodeVisitor)
		{
			_nodeVisitor.visit(*this);
		}

		void TextureNode::setupTexture(unsigned char* _buffer)
		{
			Render::TextureDescriptor descriptor;
			descriptor.mipmapped = true;
			descriptor.type = mType;
			descriptor.format = mFormat;
			descriptor.region = Region::regionMake2D(0, 0, mWidth, mHeight);
			descriptor.name = mName;

			mTexture = Render::Device::make_shared<Render::Texture>(descriptor);

			PixelData pixelData1(_buffer, mChannel == 4 ? PixelFormat::RGBA : PixelFormat::RGB, DataType::UNSIGNED_BYTE);
			mTexture->replaceRegion(pixelData1);

		}

	}
}
