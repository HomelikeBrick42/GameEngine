#pragma once

#include "BrickEngine/Renderer/Renderer.hpp"

namespace BrickEngine {

	class OpenGLRenderer final : public Renderer
	{
	public:
		OpenGLRenderer(Window* window);
		~OpenGLRenderer();

		virtual void SetClearColor(double red, double green, double blue, double alpha = 1.0f) override final;
		virtual void Clear() override final;

		virtual void Draw(uint64 first, uint64 count) override final;

		virtual void SwapBuffers() override final;

		virtual SharedPtr<Shader> CreateShader(const std::string& vertexSource, const std::string& fragmentSource) override final;
		virtual SharedPtr<VertexBuffer> CreateVertexBuffer(const void* data, uint64 size, const VertexLayout& layout)override final;
	private:
		Window* m_Window;
	};

}
