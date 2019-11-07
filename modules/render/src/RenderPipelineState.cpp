#include "RenderPipelineState.h"

namespace Render
{
	void RenderPipelineState::updateTextures()
	{
		for (const auto& tex : mRenderPieplineDescriptor->textures)
		{
			auto texture = tex.first;
			auto sampler = tex.second;

			texture->bind();
			sampler->bind();
			int uniformPosition = glGetUniformLocation(mShaderProgramId, texture->getName().c_str());

			glUniform1i(uniformPosition, texture->getTextureUnitIndex());
		}
	}

	RenderPipelineState::RenderPipelineState(std::unique_ptr<RenderPieplineDescriptor>& _renderPieplineDescriptor)
	{
		mRenderPieplineDescriptor = std::move(_renderPieplineDescriptor);
	}

	void RenderPipelineState::link()
	{
		mShaderProgramId = glCreateProgram();

		glAttachShader(mShaderProgramId, mRenderPieplineDescriptor->vertexShader->getShaderId());
		glAttachShader(mShaderProgramId, mRenderPieplineDescriptor->fragmentShader->getShaderId());

		if (mRenderPieplineDescriptor->geometryShader)
			glAttachShader(mShaderProgramId, mRenderPieplineDescriptor->geometryShader->getShaderId());

		glLinkProgram(mShaderProgramId);

		// check for linking errors
		int success;
		char infoLog[512];
		glGetProgramiv(mShaderProgramId, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(mShaderProgramId, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		}

		updateTextures();
	}

	void RenderPipelineState::use()
	{
		for (const auto& tex : mRenderPieplineDescriptor->textures)
		{
			auto texture = tex.first;
			texture->bind();
		}
		glUseProgram(mShaderProgramId);
	}


	void RenderPipelineState::unuse()
	{
		glUseProgram(0);
	}

	int RenderPipelineState::getId()
	{
		return mShaderProgramId;
	}
}
