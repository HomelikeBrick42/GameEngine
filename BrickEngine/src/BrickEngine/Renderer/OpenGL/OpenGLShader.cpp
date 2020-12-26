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

}
