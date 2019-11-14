#pragma once

#include "Node.h"

#include <Shader.h>

namespace Safaga
{
	namespace Core
	{
		class ShaderNode : public Node
		{
		public:
			ShaderNode(const char* _vertexShaderSource, const char* _fragmentShaderSource);
			void accept(INodeVisitor& _nodeVisitor) override;

		private:
			std::unique_ptr<Render::Shader>          mFragmentShader;
			std::unique_ptr<Render::Shader>          mVertexShader;
		};
	}
}
