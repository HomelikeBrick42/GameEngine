#include "brickpch.hpp"
#include "BrickEngine/Renderer/VertexBuffer.hpp"

#include "BrickEngine/Renderer/OpenGL/OpenGLVertexBuffer.hpp"

namespace BrickEngine {

	SharedPtr<VertexBuffer> VertexBuffer::Create(const void* data, uint64 size, const VertexLayout& layout)
	{
		return CreateShared<OpenGLVertexBuffer>(data, size, layout);
	}

}
