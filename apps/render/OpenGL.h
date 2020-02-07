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
#include <glm/glm.hpp>

class OpenGL
{
public:

	OpenGL();
	void draw();
	~OpenGL();

private:
	std::shared_ptr<Safaga::Render::Texture>                         mTexture1;
	std::shared_ptr<Safaga::Render::Texture>                         mTexture2;
	std::shared_ptr<Safaga::Render::Sampler>                         mTextureSampler;
	std::shared_ptr<Safaga::Render::Shader>                          mVertexShader;
	std::shared_ptr<Safaga::Render::Shader>                          mFragmentShader;
	std::shared_ptr<Safaga::Render::VertexBuffer>                    mVertexBuffer;
	std::vector<std::shared_ptr<Safaga::Render::UniformBuffer>>      mUniformBuffers;
	std::shared_ptr<Safaga::Render::RenderPipelineState>             mRenderPipelineState;
	std::unique_ptr<Safaga::Render::Drawer>                          mDrawer;

	GLFWwindow*  mWindow;


	// Camera
	glm::mat4 mModel;
	glm::mat4 mView;
	glm::mat4 mProjection;

	void setupSampler();
	void setupTextures();
	void setupUniformBuffers();
	void setupVertexBuffer();
	void setupRenderPipeline();
	void setupDrawer();

};
