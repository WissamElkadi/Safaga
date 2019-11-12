#pragma once

#include <iostream>
#include <memory>

//Render
#include <Shader.h>
#include <VertexBuffer.h>
#include <Drawer.h>
#include <Uniform.h>
#include <UniformBuffer.h>
#include <Device.h>
#include <Texture.h>
#include <Sampler.h>

//Core
#include <Camera.h>

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class Core
{
public:

	Core();
	void draw();
	~Core();

private:
	std::unique_ptr<Safaga::Render::Texture>                         mTexture1;
	std::unique_ptr<Safaga::Render::Texture>                         mTexture2;
	std::unique_ptr<Safaga::Render::Sampler>                         mTextureSampler;
	std::unique_ptr<Safaga::Render::Shader>                          mVertexShader;
	std::unique_ptr<Safaga::Render::Shader>                          mFragmentShader;
	std::unique_ptr<Safaga::Render::VertexBuffer>                    mVertexBuffer;
	std::vector<std::shared_ptr<Safaga::Render::UniformBuffer>>      mUniformBuffers;
	std::unique_ptr<Safaga::Render::RenderPipelineState>             mRenderPipelineState;
	std::unique_ptr<Safaga::Render::Drawer>                          mDrawer;

	GLFWwindow*  mWindow;

	// Cube Model
	std::vector<glm::vec3> mCubesPosition;

	// timing
	float mDeltaTime = 0.0f;
	float mLastFrame = 0.0f;

	void processInput();

	void setupCamera();
	void setupSampler();
	void setupTextures();
	void setupUniformBuffers();
	void setupVertexBuffer();
	void setupRenderPipeline();
	void setupDrawer();
};
