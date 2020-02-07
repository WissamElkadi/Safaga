#pragma once

#include "Node.h"
#include "Mesh.h"

#include <VertexBuffer.h>
#include <Texture.h>
#include <Sampler.h>
namespace Safaga
{
	namespace Core
	{
		class Renderable : public Node
		{
		public:
			void accept(INodeVisitor& _nodeVisitor) override;

		private:
			std::unique_ptr<Mesh>                                  mMesh;
			std::shared_ptr<Render::VertexBuffer>                  mVertexBuffer;
			std::vector<std::shared_ptr<Render::Texture>>          mTextures;
			std::shared_ptr<Render::Sampler>                       mNearestSampler;
			std::shared_ptr<Render::Sampler>                       mLinearSampler;

			void setupVertexBuffer();
			void setupSampler();
		};
	}
}
