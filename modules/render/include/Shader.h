#pragma once

#include<iostream>

#include "Types.h"
#include "Mapper.h"

namespace Safaga
{
	namespace Render
	{
		class Shader
		{
		public:
			Shader(const char* _shaderSource, ShaderType _shaderType);

			int getShaderId() const;

			void deleteShader();

			~Shader();

		private:
			int          mShaderId;
		};
	}
}
