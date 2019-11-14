#pragma once

#include <memory>

namespace Safaga
{
	namespace Core
	{
		class Renderable;
		class TextureNode;
		class SamplerNode;
		class ShaderNode;
		class CameraNode;
		class LightNode;
		class TransformNode;
		class SwitchNode;

		class INodeVisitor
		{
		public:
			virtual void visit(Renderable& node) = 0;
			virtual void visit(TextureNode& node) = 0;
			virtual void visit(SamplerNode& node) = 0;
			virtual void visit(ShaderNode& node) = 0;
			virtual void visit(CameraNode& node) = 0;
			virtual void visit(LightNode&  node) = 0;
			virtual void visit(TransformNode& node) = 0;
			virtual void visit(SwitchNode& node) = 0;
		};
	}
}
