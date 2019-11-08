#include "OpenGL.h"

#include <FileReader.h>

#include <glm/glm.hpp>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void OpenGL::setupSampler()
{
	/// SAMPLER
	Render::SamplerDescriptor samplerDescriptor;
	samplerDescriptor.textureType = TextureType::TEXTURE_2D;
	samplerDescriptor.sWrap = TextureWrap::REPEAT;
	samplerDescriptor.tWrap = TextureWrap::REPEAT;
	samplerDescriptor.magFilter = TextureFilter::LINEAR;
	samplerDescriptor.minFilter = TextureFilter::LINEAR;

	mTextureSampler = std::make_unique<Render::Sampler>(samplerDescriptor);
}

void OpenGL::setupTextures()
{
	/// TEXTURE 1
	int width, height, channel;
	auto imageDataBuffer = Platform::FileReader::loadImageData("C:/Users/mohammew/Documents/Wissam/Safaga/apps/render/res/container.jpg", width, height, channel);

	Render::TextureDescriptor textureDecriptor1;
	textureDecriptor1.mipmapped = true;
	textureDecriptor1.type = TextureType::TEXTURE_2D;
	textureDecriptor1.format = PixelFormat::RGB;
	textureDecriptor1.region = Region::regionMake2D(0, 0, width, height);
	textureDecriptor1.name = "texture1";

	mTexture1 = std::make_unique<Render::Texture>(textureDecriptor1);

	PixelData pixelData1(imageDataBuffer, channel == 4 ? PixelFormat::RGBA : PixelFormat::RGB, DataType::UNSIGNED_BYTE);
	mTexture1->replaceRegion(pixelData1);

	Platform::FileReader::unloadImageData(imageDataBuffer);

	/// TEXTURE 2
	imageDataBuffer = Platform::FileReader::loadImageData("C:/Users/mohammew/Documents/Wissam/Safaga/apps/render/res/awesomeface.png", width, height, channel);

	Render::TextureDescriptor textureDecriptor2;
	textureDecriptor2.mipmapped = true;
	textureDecriptor2.type = TextureType::TEXTURE_2D;
	textureDecriptor2.format = PixelFormat::RGB;
	textureDecriptor2.region = Region::regionMake2D(0, 0, width, height);
	textureDecriptor2.name = "texture2";

	mTexture2 = std::make_unique<Render::Texture>(textureDecriptor2);

	PixelData pixelData2(imageDataBuffer, channel == 4 ? PixelFormat::RGBA : PixelFormat::RGB, DataType::UNSIGNED_BYTE);
	mTexture2->replaceRegion(pixelData2);

	Platform::FileReader::unloadImageData(imageDataBuffer);
}

void OpenGL::setupUniformBuffers()
{
	std::vector<float> color = { 0.f, 1.0f, 0.0f, 1.0f };
	std::shared_ptr<Render::UniformBuffer> colorUniformBuffer = std::make_shared<Render::Uniform<float>>("ourColor", MemoryFormat::FLOAT4, color.data());

	mUniformBuffers.push_back(colorUniformBuffer);
}

void OpenGL::setupVertexBuffer()
{
	std::vector<unsigned int> indices = {  // note that we start from 0!
	0, 1, 3,  // first Triangle
	1, 2, 3   // second Triangle
	};

	std::vector<float> vertices = {
		// positions		  // coordinates
		0.5f,  0.5f, 0.0f,   1.0f, 1.0f,   // top right
		0.5f, -0.5f, 0.0f,   1.0f, 0.0f,   // bottom right
	   -0.5f, -0.5f, 0.0f,   0.0f, 0.0f,   // bottom left
	   -0.5f,  0.5f, 0.0f,   0.0f, 1.0f	// top left 
	};

	// Vertex Buffer Descriptor
	Render::VertexDescriptor vertexDescriptor;
	vertexDescriptor.attributes.resize(2);
	vertexDescriptor.layouts.resize(1);

	vertexDescriptor.attributes[0].type = Type::FLOAT;
	vertexDescriptor.attributes[0].count = 3;
	vertexDescriptor.attributes[0].bufferIndex = 0;
	vertexDescriptor.attributes[0].offset = 0;
	vertexDescriptor.attributes[1].type = Type::FLOAT;
	vertexDescriptor.attributes[1].count = 2;
	vertexDescriptor.attributes[1].bufferIndex = 0;
	vertexDescriptor.attributes[1].offset = MemoryLayout<MemoryFormat::FLOAT3>::stride();

	vertexDescriptor.layouts[0].stride = MemoryLayout<MemoryFormat::FLOAT3>::stride() + MemoryLayout<MemoryFormat::FLOAT2>::stride();

	std::vector<std::vector<float>>verticesList;
	verticesList.push_back(vertices);
	mVertexBuffer = std::make_unique<Render::VertexBuffer>(vertexDescriptor, verticesList, indices);
}

void OpenGL::setupRenderPipeline()
{

	mVertexShader = std::make_unique<Render::Shader>("C:/Users/mohammew/Documents/Wissam/Safaga/apps/render/res/triangle.ver.glsl", ShaderType::VERTEX);
	mFragmentShader = std::make_unique<Render::Shader>("C:/Users/mohammew/Documents/Wissam/Safaga/apps/render/res/triangle.frag.glsl", ShaderType::FRAGMENT);

	std::unique_ptr<Render::RenderPieplineDescriptor> renderPieplineDescriptor = std::make_unique<Render::RenderPieplineDescriptor>();
	renderPieplineDescriptor->vertexShader = mVertexShader.get();
	renderPieplineDescriptor->fragmentShader = mFragmentShader.get();
	renderPieplineDescriptor->textures = { { mTexture1.get() , mTextureSampler.get()},
										   { mTexture2.get() , mTextureSampler.get()}
	};

	mRenderPipelineState = std::make_unique<Render::RenderPipelineState>(renderPieplineDescriptor);
}

void OpenGL::setupDrawer()
{
	mDrawer = std::make_unique<Render::Drawer>();
	mDrawer->setViewPort(0, 0, 800, 600);
	mDrawer->setClearColor(Color(0.2f, 0.3f, 0.3f, 1.0f));
	mDrawer->setVertexBuffer(mVertexBuffer.get());
	mDrawer->setRenderPipelineState(mRenderPipelineState.get());
	mDrawer->setUniformBuffers(mUniformBuffers);
}

OpenGL::OpenGL()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	mWindow = glfwCreateWindow(800, 600, "OpenGL", NULL, NULL);
	if (mWindow == NULL)
	{
		glfwTerminate();
		throw std::exception("Failed to create GLFW window");
	}
	glfwMakeContextCurrent(mWindow);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		throw std::exception("Failed to initialize GLAD");
	}

	glfwSetFramebufferSizeCallback(mWindow, framebuffer_size_callback);

     setupSampler();
     setupTextures(); 
     setupUniformBuffers();
     setupVertexBuffer();
     setupRenderPipeline();
     setupDrawer();
}

void OpenGL::draw()
{
	std::vector<float> red = { 1.0f, 0.0f, 0.0f, 1.0f };

	while (!glfwWindowShouldClose(mWindow))
	{
		processInput(mWindow);

		// draw our first triangle
		mDrawer->drawElements(DrawingPrimitive::TRIANGLES, Type::UNSIGNED_INT);
		dynamic_cast<Render::Uniform<float>*>(mUniformBuffers.at(0).get())->updateValue(red.data());

		glfwSwapBuffers(mWindow);
		glfwPollEvents();
	}
}

OpenGL::~OpenGL()
{
	glfwTerminate();
}
