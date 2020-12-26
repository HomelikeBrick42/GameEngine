#pragma once

#include "BrickEngine/Core/Base.hpp"

namespace BrickEngine {

	class BRICKENGINE_API Shader
	{
	public:
		virtual ~Shader() = default;

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;
	protected:
		Shader() = default;
	private:
		Shader(const Shader&) = delete;
		Shader& operator=(const Shader&) = delete;
	};

}
