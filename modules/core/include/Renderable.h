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
			std::unique_ptr<Render::VertexBuffer>                  mVertexBuffer;
			std::vector<std::unique_ptr<Render::Texture>>          mTextures;
			std::unique_ptr<Render::Sampler>                       mNearestSampler;
			std::unique_ptr<Render::Sampler>                       mLinearSampler;

			void setupVertexBuffer();
			void setupSampler();
		};
	}
}
