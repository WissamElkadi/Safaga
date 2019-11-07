#pragma once

#include <string>

namespace Platform
{
	class FileReader
	{
	public:
		static std::string getContent(const char* shaderPath);

		static unsigned char* loadImageData(const char* imagePath, int& _width, int& _height, int& _nrChannels);

		static void unloadImageData(unsigned char *_dataBuffer);
	};
}
