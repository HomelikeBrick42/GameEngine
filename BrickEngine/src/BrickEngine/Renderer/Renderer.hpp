#pragma once

#include "BrickEngine/Core/Base.hpp"

#include "BrickEngine/Core/Window.hpp"

#include "BrickEngine/Renderer/VertexBuffer.hpp"
#include "BrickEngine/Renderer/Shader.hpp"

namespace BrickEngine {

	class BRICKENGINE_API Renderer
	{
	public:
		virtual ~Renderer() = default;

		virtual void SetClearColor(double red, double green, double blue, double alpha = 1.0f) = 0;
		virtual void Clear() = 0;

		virtual void Draw(uint64 first, uint64 count) = 0;

		virtual void SwapBuffers() = 0;

		virtual SharedPtr<Shader> CreateShader(const std::string& vertexSource, const std::string& fragmentSource) = 0;
		virtual SharedPtr<VertexBuffer> CreateVertexBuffer(const void* data, uint64 size, const VertexLayout& layout) = 0;

		static ScopePtr<Renderer> Create(Window* window);
	protected:
		Renderer() = default;
	private:
		Renderer(const Renderer&) = delete;
		Renderer& operator=(const Renderer&) = delete;
	};

}
