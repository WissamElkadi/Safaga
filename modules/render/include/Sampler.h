#pragma once

#include <array>

#include "Types.h"
#include "Mapper.h"
#include "DataStructure.h"
#include "SamplerDescriptor.h"

namespace Safaga
{
	namespace Render
	{
		class Sampler
		{
		public:
			void bind();

		private:
			SamplerDescriptor mSamplerDescriptor;

			Sampler(SamplerDescriptor& _descriptor);

			friend class Device;
			friend class std::_Ref_count_obj<Sampler>;
		};
	}
}
