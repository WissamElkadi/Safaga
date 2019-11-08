#pragma once

#include <iostream>
#include <memory>

#include <Shader.h>
#include <VertexBuffer.h>
#include <Drawer.h>
#include <Uniform.h>
#include <UniformBuffer.h>
#include <Device.h>
#include <Texture.h>
#include <Sampler.h>

#include <GLFW/glfw3.h>

class OpenGL
{
public:

	OpenGL();
	void draw();
	~OpenGL();

private:
	std::unique_ptr<Render::Texture>                         mTexture1;
	std::unique_ptr<Render::Texture>                         mTexture2;
	std::unique_ptr<Render::Sampler>                         mTextureSampler;
	std::unique_ptr<Render::Shader>                          mVertexShader;
	std::unique_ptr<Render::Shader>                          mFragmentShader;
	std::unique_ptr<Render::VertexBuffer>                    mVertexBuffer;
	std::vector<std::shared_ptr<Render::UniformBuffer>>      mUniformBuffers;
	std::unique_ptr<Render::RenderPipelineState>             mRenderPipelineState;
	std::unique_ptr<Render::Drawer>                          mDrawer;

	GLFWwindow*  mWindow;

	void setupSampler();
	void setupTextures();
	void setupUniformBuffers();
	void setupVertexBuffer();
	void setupRenderPipeline();
	void setupDrawer();

};
