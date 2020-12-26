#pragma once

#include "BrickEngine/Core/Base.hpp"

#include "BrickEngine/Core/Window.hpp"
#include "BrickEngine/Renderer/VertexBuffer.hpp"

namespace BrickEngine {

	class Renderer
	{
	public:
		virtual ~Renderer() = default;

		virtual void SwapBuffers() = 0;

		virtual SharedPtr<VertexBuffer> CreateVertexBuffer(const void* data, uint64 size, const VertexLayout& layout) = 0;

		static ScopePtr<Renderer> Create(Window* window);
	protected:
		Renderer() = default;
	private:
		Renderer(const Renderer&) = delete;
		Renderer& operator=(const Renderer&) = delete;
	};

}
