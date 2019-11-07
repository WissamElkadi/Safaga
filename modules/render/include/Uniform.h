#pragma once

#include<string>

#include "Types.h"
#include "UniformBuffer.h"

namespace Render
{
	template<typename T>
	class Uniform : public UniformBuffer
	{
	public:
		Uniform(std::string _name, MemoryFormat _MemoryFormat);

		Uniform(std::string _name, MemoryFormat _MemoryFormat, T* _value);

		void updateValue(T* _value);

		void updateValue(int _programId, const T* _value);

		MemoryFormat getMemoryFormat() override;

		void update(int _programId);

	private:
		T*          mValue;
		std::string mName;
		MemoryFormat mMemoryFormat;
	};
}

#include "Uniform.hpp"
