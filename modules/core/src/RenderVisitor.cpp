#include "RenderVisitor.h"

#include "Renderable.h"
#include "CameraNode.h"
#include "LightNode.h"
#include "TransformNode.h"
#include "SwitchNode.h"

namespace Safaga
{
	namespace Core
	{
		RenderVisitor::RenderVisitor(int _screenWidth, int _screenHeight) :
			mScreenWidth(_screenWidth), mScreenHeight(_screenHeight)
		{
		}

		void RenderVisitor::visit(Renderable& node)
		{
		}

		void RenderVisitor::visit(TextureNode& node)
		{
		}

		void RenderVisitor::visit(SamplerNode& node)
		{
		}

		void RenderVisitor::visit(CameraNode& node)
		{
		}

		void RenderVisitor::visit(LightNode&  node)
		{
		}

		void RenderVisitor::visit(TransformNode&  node)
		{
		}

		void RenderVisitor::visit(SwitchNode& node)
		{
		}
	}
}
