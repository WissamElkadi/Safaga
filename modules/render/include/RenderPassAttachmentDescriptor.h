#pragma once

#include "Texture.h"

namespace Safaga
{
	namespace Render
	{
		struct RenderPassAttachmentDescriptor
		{
			std::shared_ptr<Texture> texture;
			LoadAction               loadAcrion;
			StoreAction              storeAction;
			Color                    clearValue;
		};
	}
}