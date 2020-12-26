#pragma once

#include "BrickEngine/Core/Base.hpp"

#include "BrickEngine/Renderer/VertexLayout.hpp"

namespace BrickEngine {

	class BRICKENGINE_API VertexBuffer
	{
	public:
		virtual ~VertexBuffer() = default;

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		virtual void SetLayout(const VertexLayout& layout) = 0;
		virtual void SetData(const void* data, uint64 size) = 0;
	protected:
		VertexBuffer() = default;
	private:
		VertexBuffer(const VertexBuffer&) = delete;
		VertexBuffer& operator=(const VertexBuffer&) = delete;
	};

}
