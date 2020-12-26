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

		virtual void SetDouble(const std::string& name, float64 v) override final;
		virtual void SetFloat(const std::string& name, float32 v) override final;
		virtual void SetInt(const std::string& name, int32 v) override final;
		virtual void SetUInt(const std::string& name, uint32 v) override final;

		virtual void SetVector2(const std::string& name, const Vector2d& v) override final;
		virtual void SetVector2(const std::string& name, const Vector2f& v) override final;
		virtual void SetVector2(const std::string& name, const Vector2i& v) override final;
		virtual void SetVector2(const std::string& name, const Vector2u& v) override final;

		virtual void SetVector3(const std::string& name, const Vector3d& v) override final;
		virtual void SetVector3(const std::string& name, const Vector3f& v) override final;
		virtual void SetVector3(const std::string& name, const Vector3i& v) override final;
		virtual void SetVector3(const std::string& name, const Vector3u& v) override final;

		virtual void SetVector4(const std::string& name, const Vector4d& v) override final;
		virtual void SetVector4(const std::string& name, const Vector4f& v) override final;
		virtual void SetVector4(const std::string& name, const Vector4i& v) override final;
		virtual void SetVector4(const std::string& name, const Vector4u& v) override final;
	private:
		uint32 m_RendererID = 0;
	};

}
