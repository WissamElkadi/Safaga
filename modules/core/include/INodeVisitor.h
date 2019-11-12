#pragma once

#include <memory>

namespace Safaga
{
	namespace Core
	{
		class Renderable;
		class CameraNode;
		class Light;
		class Transform;
		class Switch;

		class INodeVisitor
		{
		public:
			virtual void visit(Renderable& node) = 0;
			virtual void visit(CameraNode& node) = 0;
			virtual void visit(Light&  node) = 0;
			virtual void visit(Transform& node) = 0;
			virtual void visit(Switch& node) = 0;
		};
	}
}
