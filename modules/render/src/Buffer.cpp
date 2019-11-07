#include "Buffer.h"

namespace Platform 
{
	 namespace Render
	 {

		Buffer::Buffer(void** _content)
		{
			mContent = *_content;
		}

		void* Buffer::data()
		{
			return mContent;
		}

	}
}
