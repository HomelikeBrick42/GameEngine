#pragma once

#include "BrickEngine/Core/Base.hpp"

#include "BrickEngine/Renderer/ShaderDataTypes.hpp"

namespace BrickEngine {

	class BRICKENGINE_API VertexLayout
	{
	public:
		struct BRICKENGINE_API VertexElement
		{
			ShaderDataType Type = ShaderDataType::Invalid;
			std::string Name = "";
			bool Normalized = false;
		};
	public:
		VertexLayout() = default;
		VertexLayout(const std::vector<VertexElement>& elements)
			: m_Elements(elements) {}
		VertexLayout(const std::initializer_list<VertexElement>& elements)
			: m_Elements(elements) {}

		std::vector<VertexElement>& GetElements() { return m_Elements; }
		const std::vector<VertexElement>& GetElements() const { return m_Elements; }
	private:
		std::vector<VertexElement> m_Elements;
	};

}
