#pragma once

#include "BrickEngine/Core/Base.hpp"

#include "BrickEngine/Math/Vector1.hpp"
#include "BrickEngine/Math/Vector2.hpp"
#include "BrickEngine/Math/Vector3.hpp"
#include "BrickEngine/Math/Vector4.hpp"

namespace BrickEngine {

	class BRICKENGINE_API Shader
	{
	public:
		virtual ~Shader() = default;

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		virtual void SetDouble(const std::string& name, float64 v) = 0;
		virtual void SetFloat(const std::string& name, float32 v) = 0;
		virtual void SetInt(const std::string& name, int32 v) = 0;
		virtual void SetUInt(const std::string& name, uint32 v) = 0;

		virtual void SetVector2(const std::string& name, const Vector2d& v) = 0;
		virtual void SetVector2(const std::string& name, const Vector2f& v) = 0;
		virtual void SetVector2(const std::string& name, const Vector2i& v) = 0;
		virtual void SetVector2(const std::string& name, const Vector2u& v) = 0;

		virtual void SetVector3(const std::string& name, const Vector3d& v) = 0;
		virtual void SetVector3(const std::string& name, const Vector3f& v) = 0;
		virtual void SetVector3(const std::string& name, const Vector3i& v) = 0;
		virtual void SetVector3(const std::string& name, const Vector3u& v) = 0;

		virtual void SetVector4(const std::string& name, const Vector4d& v) = 0;
		virtual void SetVector4(const std::string& name, const Vector4f& v) = 0;
		virtual void SetVector4(const std::string& name, const Vector4i& v) = 0;
		virtual void SetVector4(const std::string& name, const Vector4u& v) = 0;
	protected:
		Shader() = default;
	private:
		Shader(const Shader&) = delete;
		Shader& operator=(const Shader&) = delete;
	};

}
