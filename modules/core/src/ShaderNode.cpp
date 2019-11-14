#include "ShaderNode.h"

namespace Safaga
{
	namespace Core
	{
		ShaderNode::ShaderNode(const char* _vertexShaderSource, const char* _fragmentShaderSource)
		{
			mVertexShader = std::make_unique<Safaga::Render::Shader>(_vertexShaderSource, ShaderType::VERTEX);
			mFragmentShader = std::make_unique<Safaga::Render::Shader>(_fragmentShaderSource, ShaderType::FRAGMENT);
		}

		void ShaderNode::accept(INodeVisitor& _nodeVisitor)
		{
			_nodeVisitor.visit(*this);
		}
	}
}
