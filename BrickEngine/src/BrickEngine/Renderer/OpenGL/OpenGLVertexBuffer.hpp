#pragma once

#include "BrickEngine/Renderer/VertexBuffer.hpp"

namespace BrickEngine {

	class OpenGLVertexBuffer final : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(const void* data, uint64 size, const VertexLayout& layout);
		~OpenGLVertexBuffer();

		virtual void Bind() const override final;
		virtual void UnBind() const override final;

		virtual void SetLayout(const VertexLayout& layout) override final;
		virtual void SetData(const void* data, uint64 size) override final;
	private:
		uint32 m_RendererID = 0;
		uint32 m_VertexArrayID = 0;
		uint64 m_MaxSize = 0;
	};

}
