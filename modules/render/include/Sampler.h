#pragma once

#include <array>

#include "Types.h"
#include "Mapper.h"
#include "DataStructure.h"
#include "SamplerDescriptor.h"

namespace Render
{
	class Sampler
	{
	public:

		Sampler(SamplerDescriptor _descriptor);

		void bind();

	private:
		SamplerDescriptor mSamplerDescriptor;
	};
}
