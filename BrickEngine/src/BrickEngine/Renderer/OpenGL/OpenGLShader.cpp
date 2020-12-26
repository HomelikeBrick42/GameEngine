#include "brickpch.hpp"
#include "BrickEngine/Renderer/OpenGL/OpenGLShader.hpp"

#include <glad/glad.h>

namespace BrickEngine {

	OpenGLShader::OpenGLShader(const std::string& vertexSource, const std::string& fragmentSource)
	{
		m_RendererID = glCreateProgram();

		const GLchar* vertexSrc = vertexSource.c_str();
		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexSrc, nullptr);
		glCompileShader(vertexShader);
		
		GLint success;
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			GLint maxLength = 0;
			glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<GLchar> errorLog(maxLength);
			glGetShaderInfoLog(vertexShader, maxLength, &maxLength, &errorLog[0]);

			BRICKENGINE_DEBUG_ERROR(errorLog.data());
		}

		const GLchar* fragmentSrc = fragmentSource.c_str();
		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentSrc, nullptr);
		glCompileShader(fragmentShader);

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			GLint maxLength = 0;
			glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<GLchar> errorLog(maxLength);
			glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, &errorLog[0]);

			BRICKENGINE_DEBUG_ERROR(errorLog.data());
		}

		glAttachShader(m_RendererID, vertexShader);
		glAttachShader(m_RendererID, fragmentShader);
		glLinkProgram(m_RendererID);

		glGetProgramiv(m_RendererID, GL_LINK_STATUS, &success);
		if (!success)
		{
			GLint maxLength = 0;
			glGetProgramiv(m_RendererID, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<GLchar> errorLog(maxLength);
			glGetProgramInfoLog(m_RendererID, maxLength, &maxLength, &errorLog[0]);

			BRICKENGINE_DEBUG_ERROR(errorLog.data());
		}

		glDetachShader(m_RendererID, vertexShader);
		glDeleteShader(vertexShader);
		glDetachShader(m_RendererID, fragmentShader);
		glDeleteShader(fragmentShader);
	}

	OpenGLShader::~OpenGLShader()
	{
		glDeleteProgram(m_RendererID);
	}

	void OpenGLShader::Bind() const
	{
		glUseProgram(m_RendererID);
	}

	void OpenGLShader::UnBind() const
	{
		glUseProgram(0);
	}

	void OpenGLShader::SetDouble(const std::string& name, float64 v)
	{
		int32 location = glGetUniformLocation(m_RendererID, name.c_str());
		if (location == -1)
			BRICKENGINE_DEBUG_ERROR("Unable to find uniform '%s'", name.c_str());
		else
			glProgramUniform1d(m_RendererID, location, v);
	}

	void OpenGLShader::SetFloat(const std::string& name, float32 v)
	{
		int32 location = glGetUniformLocation(m_RendererID, name.c_str());
		if (location == -1)
			BRICKENGINE_DEBUG_ERROR("Unable to find uniform '%s'", name.c_str());
		else
			glProgramUniform1f(m_RendererID, location, v);
	}

	void OpenGLShader::SetInt(const std::string& name, int32 v)
	{
		int32 location = glGetUniformLocation(m_RendererID, name.c_str());
		if (location == -1)
			BRICKENGINE_DEBUG_ERROR("Unable to find uniform '%s'", name.c_str());
		else
			glProgramUniform1i(m_RendererID, location, v);
	}

	void OpenGLShader::SetUInt(const std::string& name, uint32 v)
	{
		int32 location = glGetUniformLocation(m_RendererID, name.c_str());
		if (location == -1)
			BRICKENGINE_DEBUG_ERROR("Unable to find uniform '%s'", name.c_str());
		else
			glProgramUniform1ui(m_RendererID, location, v);
	}

	void OpenGLShader::SetVector2(const std::string& name, const Vector2d& v)
	{
		int32 location = glGetUniformLocation(m_RendererID, name.c_str());
		if (location == -1)
			BRICKENGINE_DEBUG_ERROR("Unable to find uniform '%s'", name.c_str());
		else
			glProgramUniform2d(m_RendererID, location, v.x, v.y);
	}

	void OpenGLShader::SetVector2(const std::string& name, const Vector2f& v)
	{
		int32 location = glGetUniformLocation(m_RendererID, name.c_str());
		if (location == -1)
			BRICKENGINE_DEBUG_ERROR("Unable to find uniform '%s'", name.c_str());
		else
			glProgramUniform2f(m_RendererID, location, v.x, v.y);
	}

	void OpenGLShader::SetVector2(const std::string& name, const Vector2i& v)
	{
		int32 location = glGetUniformLocation(m_RendererID, name.c_str());
		if (location == -1)
			BRICKENGINE_DEBUG_ERROR("Unable to find uniform '%s'", name.c_str());
		else
			glProgramUniform2i(m_RendererID, location, v.x, v.y);
	}

	void OpenGLShader::SetVector2(const std::string& name, const Vector2u& v)
	{
		int32 location = glGetUniformLocation(m_RendererID, name.c_str());
		if (location == -1)
			BRICKENGINE_DEBUG_ERROR("Unable to find uniform '%s'", name.c_str());
		else
			glProgramUniform2ui(m_RendererID, location, v.x, v.y);
	}

	void OpenGLShader::SetVector3(const std::string& name, const Vector3d& v)
	{
		int32 location = glGetUniformLocation(m_RendererID, name.c_str());
		if (location == -1)
			BRICKENGINE_DEBUG_ERROR("Unable to find uniform '%s'", name.c_str());
		else
			glProgramUniform3d(m_RendererID, location, v.x, v.y, v.z);
	}

	void OpenGLShader::SetVector3(const std::string& name, const Vector3f& v)
	{
		int32 location = glGetUniformLocation(m_RendererID, name.c_str());
		if (location == -1)
			BRICKENGINE_DEBUG_ERROR("Unable to find uniform '%s'", name.c_str());
		else
			glProgramUniform3f(m_RendererID, location, v.x, v.y, v.z);
	}

	void OpenGLShader::SetVector3(const std::string& name, const Vector3i& v)
	{
		int32 location = glGetUniformLocation(m_RendererID, name.c_str());
		if (location == -1)
			BRICKENGINE_DEBUG_ERROR("Unable to find uniform '%s'", name.c_str());
		else
			glProgramUniform3i(m_RendererID, location, v.x, v.y, v.z);
	}

	void OpenGLShader::SetVector3(const std::string& name, const Vector3u& v)
	{
		int32 location = glGetUniformLocation(m_RendererID, name.c_str());
		if (location == -1)
			BRICKENGINE_DEBUG_ERROR("Unable to find uniform '%s'", name.c_str());
		else
			glProgramUniform3ui(m_RendererID, location, v.x, v.y, v.z);
	}

	void OpenGLShader::SetVector4(const std::string& name, const Vector4d& v)
	{
		int32 location = glGetUniformLocation(m_RendererID, name.c_str());
		if (location == -1)
			BRICKENGINE_DEBUG_ERROR("Unable to find uniform '%s'", name.c_str());
		else
			glProgramUniform4d(m_RendererID, location, v.x, v.y, v.z, v.w);
	}

	void OpenGLShader::SetVector4(const std::string& name, const Vector4f& v)
	{
		int32 location = glGetUniformLocation(m_RendererID, name.c_str());
		if (location == -1)
			BRICKENGINE_DEBUG_ERROR("Unable to find uniform '%s'", name.c_str());
		else
			glProgramUniform4f(m_RendererID, location, v.x, v.y, v.z, v.w);
	}

	void OpenGLShader::SetVector4(const std::string& name, const Vector4i& v)
	{
		int32 location = glGetUniformLocation(m_RendererID, name.c_str());
		if (location == -1)
			BRICKENGINE_DEBUG_ERROR("Unable to find uniform '%s'", name.c_str());
		else
			glProgramUniform4i(m_RendererID, location, v.x, v.y, v.z, v.w);
	}

	void OpenGLShader::SetVector4(const std::string& name, const Vector4u& v)
	{
		int32 location = glGetUniformLocation(m_RendererID, name.c_str());
		if (location == -1)
			BRICKENGINE_DEBUG_ERROR("Unable to find uniform '%s'", name.c_str());
		else
			glProgramUniform4ui(m_RendererID, location, v.x, v.y, v.z, v.w);
	}

}
