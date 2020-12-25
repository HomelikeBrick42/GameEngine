#include "brickpch.hpp"
#include "BrickEngine/Renderer/OpenGL/OpenGLVertexBuffer.hpp"

#include <glad/glad.h>

namespace BrickEngine {

	OpenGLVertexBuffer::OpenGLVertexBuffer(const void* data, uint64 size)
	{
		glGenBuffers(1, &m_RendererID);
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
		SetData(data, size);
	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		glDeleteBuffers(1, &m_RendererID);
	}

	void OpenGLVertexBuffer::Bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
	}

	void OpenGLVertexBuffer::UnBind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void OpenGLVertexBuffer::SetData(const void* data, uint64 size)
	{
		if (size > m_MaxSize)
		{
			glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
			m_MaxSize = size;
		}
		else
		{
			glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
		}
	}

}
