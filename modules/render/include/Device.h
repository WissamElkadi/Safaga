#pragma once

#include <memory>

//#include "RenderPieplineDescriptor.h"
//#include "VertexDescriptor.h"
//#include "TextureDescriptor.h"
//#include "SamplerDescriptor.h"

namespace Safaga
{
	namespace Render
	{
		class CommandQueue;

		class Device final
		{
		public:
			static int getMaxVertexAttributes();

			template<typename T, typename... A>
			static std::shared_ptr<T> make_shared(A&&... args) {
				return std::make_shared<T>(std::forward<A>(args)...);
			}

		private:
			static std::shared_ptr<CommandQueue> mCommandQueue;
		};
	}
}
