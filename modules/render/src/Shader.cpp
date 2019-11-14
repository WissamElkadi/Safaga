#include "Shader.h"

#include <glad/glad.h>

namespace Safaga
{
	namespace Render
	{
		Shader::Shader(const char* shaderSource, ShaderType _shaderType)
		{
			mShaderId = glCreateShader(ShaderTypeMapper.at(_shaderType));
			glShaderSource(mShaderId, 1, &shaderSource, NULL);
			glCompileShader(mShaderId);

			// check for shader compile errors
			int success;
			char infoLog[1024];
			glGetShaderiv(mShaderId, GL_COMPILE_STATUS, &success);
			if (!success)
			{
				glGetShaderInfoLog(mShaderId, 1024, NULL, infoLog);
				std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
			}
		}

		int Shader::getShaderId() const
		{
			return mShaderId;
		}

		void Shader::deleteShader()
		{
			glDeleteShader(mShaderId);
		}

		Shader::~Shader()
		{
			glDeleteShader(mShaderId);
		}
	}
}
