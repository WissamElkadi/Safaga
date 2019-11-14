#pragma once

#include "INodeVisitor.h"

namespace Safaga
{
	namespace Core
	{
		class RenderVisitor : public INodeVisitor
		{
		public:
			RenderVisitor(int _screenWidth, int _screenSize);

			void visit(Renderable& node)        override;
			void visit(TextureNode& node)       override;
			void visit(SamplerNode& node)       override;
			void visit(ShaderNode& node)        override;
			void visit(CameraNode& node)        override;
			void visit(LightNode&  node)        override;
			void visit(TransformNode& node)     override;
			void visit(SwitchNode& node)        override;

		private:
			int mScreenWidth, mScreenHeight;
		};
	}
}
