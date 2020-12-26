#pragma once

#include "BrickEngine/Renderer/Shader.hpp"

namespace BrickEngine {

	class OpenGLShader final : public Shader
	{
	public:
		OpenGLShader(const std::string& vertexSource, const std::string& fragmentSource);
		~OpenGLShader();

		virtual void Bind() const override final;
		virtual void UnBind() const override final;
	private:
		uint32 m_RendererID = 0;
	};

}
