#include "Buffer.h"

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
