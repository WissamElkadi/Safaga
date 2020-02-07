#include "Renderable.h"
#include "Device.h"

namespace Safaga
{
	namespace Core
	{
		void Renderable::accept(INodeVisitor& _nodeVisitor)
		{
			_nodeVisitor.visit(*this);
		}



		void Renderable::setupVertexBuffer()
		{
			// Vertex Buffer Descriptor
			Render::VertexDescriptor vertexDescriptor;
			vertexDescriptor.attributes.resize(2);
			vertexDescriptor.layouts.resize(1);

			vertexDescriptor.attributes[0].type = Type::FLOAT;
			vertexDescriptor.attributes[0].count = 3;
			vertexDescriptor.attributes[0].bufferIndex = 0;
			vertexDescriptor.attributes[0].offset = 0;
			vertexDescriptor.attributes[1].type = Type::FLOAT;
			vertexDescriptor.attributes[1].count = 2;
			vertexDescriptor.attributes[1].bufferIndex = 0;
			vertexDescriptor.attributes[1].offset = MemoryLayout<MemoryFormat::FLOAT3>::stride();

			vertexDescriptor.layouts[0].stride = MemoryLayout<MemoryFormat::FLOAT3>::stride() + MemoryLayout<MemoryFormat::FLOAT2>::stride();

			std::vector<std::vector<float>>verticesList;
			verticesList.push_back(mMesh->getVertices());
			mVertexBuffer = Render::Device::make_shared<Render::VertexBuffer>(vertexDescriptor, verticesList, mMesh->getIndcies());
		}
	}
}
