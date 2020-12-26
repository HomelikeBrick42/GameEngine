#include "brickpch.hpp"
#include "BrickEngine/Renderer/OpenGL/OpenGLVertexBuffer.hpp"

#include <glad/glad.h>

namespace BrickEngine {

	GLenum ShaderDataTypeToOpenGLDataType(ShaderDataType type)
	{
		switch (type)
		{
		case ShaderDataType::Byte:
		case ShaderDataType::Byte2:
		case ShaderDataType::Byte3:
		case ShaderDataType::Byte4:
			return GL_BYTE;
		case ShaderDataType::UByte:
		case ShaderDataType::UByte2:
		case ShaderDataType::UByte3:
		case ShaderDataType::UByte4:
			return GL_UNSIGNED_BYTE;
		case ShaderDataType::Short:
		case ShaderDataType::Short2:
		case ShaderDataType::Short3:
		case ShaderDataType::Short4:
			return GL_SHORT;
		case ShaderDataType::UShort:
		case ShaderDataType::UShort2:
		case ShaderDataType::UShort3:
		case ShaderDataType::UShort4:
			return GL_UNSIGNED_SHORT;
		case ShaderDataType::Int:
		case ShaderDataType::Int2:
		case ShaderDataType::Int3:
		case ShaderDataType::Int4:
			return GL_INT;
		case ShaderDataType::UInt:
		case ShaderDataType::UInt2:
		case ShaderDataType::UInt3:
		case ShaderDataType::UInt4:
			return GL_UNSIGNED_INT;
		case ShaderDataType::Float:
		case ShaderDataType::Float2:
		case ShaderDataType::Float3:
		case ShaderDataType::Float4:
			return GL_FLOAT;
		case ShaderDataType::Double:
		case ShaderDataType::Double2:
		case ShaderDataType::Double3:
		case ShaderDataType::Double4:
			return GL_DOUBLE;
		}

		BRICKENGINE_ASSERT(false, "Invalid shader data type!");
		return 0;
	}

	OpenGLVertexBuffer::OpenGLVertexBuffer(const void* data, uint64 size, const VertexLayout& layout)
	{
		glGenVertexArrays(1, &m_VertexArrayID);
		glGenBuffers(1, &m_RendererID);
		SetData(data, size);
		SetLayout(layout);
	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		glDeleteBuffers(1, &m_RendererID);
	}

	void OpenGLVertexBuffer::Bind() const
	{
		glBindVertexArray(m_VertexArrayID);
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
	}

	void OpenGLVertexBuffer::UnBind() const
	{
		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void OpenGLVertexBuffer::SetLayout(const VertexLayout& layout)
	{
		Bind();
		uint64 stride = 0;
		for (auto& element : layout.GetElements())
			stride += GetShaderDataTypeElementSize(element.Type);

		uint64 offset = 0;
		uint64 index = 0;
		for (auto& element : layout.GetElements())
		{
			switch (GetShaderDataTypeBaseType(element.Type))
			{
			case ShaderDataType::Byte:
			case ShaderDataType::UByte:
			case ShaderDataType::Short:
			case ShaderDataType::UShort:
			case ShaderDataType::Int:
			case ShaderDataType::UInt:
				if (element.Normalized)
				{
					glEnableVertexAttribArray((GLuint)index);
					glVertexAttribPointer(
						(GLuint)index,
						GetShaderDataTypeCount(element.Type),
						ShaderDataTypeToOpenGLDataType(element.Type),
						element.Normalized ? GL_TRUE : GL_FALSE,
						(GLsizei)stride,
						(const void*)offset
					);
				}
				else
				{
					glEnableVertexAttribArray((GLuint)index);
					glVertexAttribIPointer(
						(GLuint)index,
						GetShaderDataTypeCount(element.Type),
						ShaderDataTypeToOpenGLDataType(element.Type),
						(GLsizei)stride,
						(const void*)offset
					);
				}
				break;
			case ShaderDataType::Float:
				glEnableVertexAttribArray((GLuint)index);
				glVertexAttribPointer(
					(GLuint)index,
					GetShaderDataTypeCount(element.Type),
					ShaderDataTypeToOpenGLDataType(element.Type),
					element.Normalized ? GL_TRUE : GL_FALSE,
					(GLsizei)stride,
					(const void*)offset
				);
				break;
			case ShaderDataType::Double:
				glEnableVertexAttribArray((GLuint)index);
				glVertexAttribLPointer(
					(GLuint)index,
					GetShaderDataTypeCount(element.Type),
					ShaderDataTypeToOpenGLDataType(element.Type),
					(GLsizei)stride,
					(const void*)offset
				);
				break;
			}

			offset += GetShaderDataTypeElementSize(element.Type);
			index++;
		}
	}

	void OpenGLVertexBuffer::SetData(const void* data, uint64 size)
	{
		Bind();
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
