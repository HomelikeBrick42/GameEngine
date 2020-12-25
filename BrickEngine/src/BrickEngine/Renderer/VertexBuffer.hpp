#pragma once

#include "BrickEngine/Core/Base.hpp"

namespace BrickEngine {

	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() = default;

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		virtual void SetData(const void* data, uint64 size) = 0;

		static SharedPtr<VertexBuffer> Create(const void* data, uint64 size);
	protected:
		VertexBuffer() = default;
	private:
		VertexBuffer(const VertexBuffer&) = delete;
		VertexBuffer& operator=(const VertexBuffer&) = delete;
	};

}
