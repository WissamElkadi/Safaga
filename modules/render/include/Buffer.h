#pragma once

#include "DataStructure.h"

namespace Safaga
{
	namespace Render
	{
		class Device;

		class Buffer
		{
		public:
			void* data();

		private:
			void* mContent;

			Buffer() = default;
			Buffer(void** _content);

			friend class Device;
		};
	}
}
