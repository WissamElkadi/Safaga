#include "OpenGL.h"

#include <FileReader.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <DepthDescriptor.h>

unsigned int SCR_WIDTH = 600;
unsigned int SCR_HEIGHT = 800;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	SCR_WIDTH = width; SCR_HEIGHT = height;
	glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
}

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void OpenGL::setupSampler()
{
	/// SAMPLER
	Safaga::Render::SamplerDescriptor samplerDescriptor;
	samplerDescriptor.textureType = TextureType::TEXTURE_2D;
	samplerDescriptor.sWrap = TextureWrap::REPEAT;
	samplerDescriptor.tWrap = TextureWrap::REPEAT;
	samplerDescriptor.magFilter = TextureFilter::LINEAR;
	samplerDescriptor.minFilter = TextureFilter::LINEAR;

	mTextureSampler = std::make_unique<Safaga::Render::Sampler>(samplerDescriptor);
}

void OpenGL::setupTextures()
{
	/// TEXTURE 1
	int width, height, channel;
	auto imageDataBuffer = Safaga::Platform::FileReader::loadImageData("C:/Users/mohammew/Documents/Wissam/Safaga/apps/render/res/container.jpg", width, height, channel);

	Safaga::Render::TextureDescriptor textureDecriptor1;
	textureDecriptor1.mipmapped = true;
	textureDecriptor1.type = TextureType::TEXTURE_2D;
	textureDecriptor1.format = PixelFormat::RGB;
	textureDecriptor1.region = Region::regionMake2D(0, 0, width, height);
	textureDecriptor1.name = "texture1";

	mTexture1 = std::make_unique<Safaga::Render::Texture>(textureDecriptor1);

	PixelData pixelData1(imageDataBuffer, channel == 4 ? PixelFormat::RGBA : PixelFormat::RGB, DataType::UNSIGNED_BYTE);
	mTexture1->replaceRegion(pixelData1);

	Safaga::Platform::FileReader::unloadImageData(imageDataBuffer);

	/// TEXTURE 2
	imageDataBuffer = Safaga::Platform::FileReader::loadImageData("C:/Users/mohammew/Documents/Wissam/Safaga/apps/render/res/awesomeface.png", width, height, channel);

	Safaga::Render::TextureDescriptor textureDecriptor2;
	textureDecriptor2.mipmapped = true;
	textureDecriptor2.type = TextureType::TEXTURE_2D;
	textureDecriptor2.format = PixelFormat::RGB;
	textureDecriptor2.region = Region::regionMake2D(0, 0, width, height);
	textureDecriptor2.name = "texture2";

	mTexture2 = std::make_unique<Safaga::Render::Texture>(textureDecriptor2);

	PixelData pixelData2(imageDataBuffer, channel == 4 ? PixelFormat::RGBA : PixelFormat::RGB, DataType::UNSIGNED_BYTE);
	mTexture2->replaceRegion(pixelData2);

	Safaga::Platform::FileReader::unloadImageData(imageDataBuffer);
}

void OpenGL::setupUniformBuffers()
{
	// Color Uniform
	Color color = { 0.f, 1.0f, 0.0f, 1.0f };
	std::shared_ptr<Safaga::Render::UniformBuffer> colorUniformBuffer = std::make_shared<Safaga::Render::Uniform<float>>("ourColor", MemoryFormat::FLOAT4, color.data());

	// Transformation Unifrom
	mModel = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	mView = glm::mat4(1.0f);
	mProjection = glm::mat4(1.0f);

	std::shared_ptr<Safaga::Render::UniformBuffer> modelUniformBuffer = std::make_shared<Safaga::Render::Uniform<float>>("model", MemoryFormat::MAT_FLOAT_4X4, glm::value_ptr(mModel));
	std::shared_ptr<Safaga::Render::UniformBuffer> viewUniformBuffer = std::make_shared<Safaga::Render::Uniform<float>>("view", MemoryFormat::MAT_FLOAT_4X4, glm::value_ptr(mView));
	std::shared_ptr<Safaga::Render::UniformBuffer> projectionUniformBuffer = std::make_shared<Safaga::Render::Uniform<float>>("projection", MemoryFormat::MAT_FLOAT_4X4, glm::value_ptr(mProjection));

	//mUniformBuffers.push_back(colorUniformBuffer);
	mUniformBuffers.push_back(modelUniformBuffer);
	mUniformBuffers.push_back(viewUniformBuffer);
	mUniformBuffers.push_back(projectionUniformBuffer);
}

void OpenGL::setupVertexBuffer()
{
	//std::vector<unsigned int> indices = {  // note that we start from 0!
	//0, 1, 3,  // first Triangle
	//1, 2, 3   // second Triangle
	//};

	std::vector<float> vertices = {
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
	};

	// Vertex Buffer Descriptor
	Safaga::Render::VertexDescriptor vertexDescriptor;
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
	mVertexBuffer = std::make_unique<Safaga::Render::VertexBuffer>(vertexDescriptor, verticesList);
}

void OpenGL::setupRenderPipeline()
{
	std::string vertexShaderSourceString = Safaga::Platform::FileReader::getContent("C:/Users/mohammew/Documents/Wissam/Safaga/apps/render/res/triangle.ver.glsl");
	std::string fragmentShaderSourceString = Safaga::Platform::FileReader::getContent("C:/Users/mohammew/Documents/Wissam/Safaga/apps/render/res/triangle.frag.glsl");

	mVertexShader = std::make_unique<Safaga::Render::Shader>(vertexShaderSourceString.c_str(), ShaderType::VERTEX);
	mFragmentShader = std::make_unique<Safaga::Render::Shader>(fragmentShaderSourceString.c_str(), ShaderType::FRAGMENT);

	std::unique_ptr<Safaga::Render::RenderPieplineDescriptor> renderPieplineDescriptor = std::make_unique<Safaga::Render::RenderPieplineDescriptor>();
	renderPieplineDescriptor->vertexShader = mVertexShader.get();
	renderPieplineDescriptor->fragmentShader = mFragmentShader.get();
	renderPieplineDescriptor->textures = { { mTexture1.get() , mTextureSampler.get()},
										   { mTexture2.get() , mTextureSampler.get()}
	};

	mRenderPipelineState = std::make_unique<Safaga::Render::RenderPipelineState>(renderPieplineDescriptor);
}

void OpenGL::setupDrawer()
{
	mDrawer = std::make_unique<Safaga::Render::Drawer>();
	mDrawer->setViewPort(ViewPort(0, 0, SCR_HEIGHT, SCR_WIDTH));
	mDrawer->setClearColor(Color(0.2f, 0.3f, 0.3f, 1.0f));
	mDrawer->setVertexBuffer(mVertexBuffer.get());
	mDrawer->setRenderPipelineState(mRenderPipelineState.get());
	mDrawer->setUniformBuffers(mUniformBuffers);
	mDrawer->setDepthDescriptor(Safaga::Render::DepthDescriptor(true, CompareFunction::LESS));
}

OpenGL::OpenGL()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	mWindow = glfwCreateWindow(SCR_HEIGHT, SCR_WIDTH, "OpenGL", NULL, NULL);
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

		//dynamic_cast<Safaga::Render::Uniform<float>*>(mUniformBuffers.at(0).get())->updateValue(red.data());

		mModel = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
		mView = glm::mat4(1.0f);
		mProjection = glm::mat4(1.0f);

		mModel = glm::rotate(mModel, (float)glfwGetTime(), glm::vec3(0.5f, 1.0f, 0.0f));
		mView = glm::translate(mView, glm::vec3(0.0f, 0.0f, -3.0f));
		mProjection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);

		// draw our first triangle
		mDrawer->begin();

		dynamic_cast<Safaga::Render::Uniform<float>*>(mUniformBuffers.at(0).get())->updateValue(glm::value_ptr(mModel));
		dynamic_cast<Safaga::Render::Uniform<float>*>(mUniformBuffers.at(1).get())->updateValue(glm::value_ptr(mView));
		dynamic_cast<Safaga::Render::Uniform<float>*>(mUniformBuffers.at(2).get())->updateValue(glm::value_ptr(mProjection));

		mDrawer->draw(DrawingPrimitive::TRIANGLES);

		mDrawer->end();

		glfwSwapBuffers(mWindow);
		glfwPollEvents();
	}
}

OpenGL::~OpenGL()
{
	glfwTerminate();
}
