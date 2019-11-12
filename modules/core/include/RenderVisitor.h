#pragma once

#include "INodeVisitor.h"

namespace Safaga
{
	namespace Core
	{
		class RenderVisitor : public INodeVisitor
		{
		public:
			void visit(Renderable& node)    override;
			void visit(CameraNode& node)    override;
			void visit(Light&  node)        override;
			void visit(Transform& node)     override;
			void visit(Switch& node)        override;
		};
	}
}
