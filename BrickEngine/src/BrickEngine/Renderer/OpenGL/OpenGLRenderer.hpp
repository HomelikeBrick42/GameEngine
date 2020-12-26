#pragma once

#include "BrickEngine/Renderer/Renderer.hpp"

namespace BrickEngine {

	class OpenGLRenderer final : public Renderer
	{
	public:
		OpenGLRenderer(Window* window);
		~OpenGLRenderer();

		virtual void SwapBuffers() override final;

		virtual SharedPtr<VertexBuffer> CreateVertexBuffer(const void* data, uint64 size, const VertexLayout& layout)override final;
	private:
		Window* m_Window;
	};

}
