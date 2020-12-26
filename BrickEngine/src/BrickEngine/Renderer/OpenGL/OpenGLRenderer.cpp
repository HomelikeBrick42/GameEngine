#include "brickpch.hpp"
#include "BrickEngine/Renderer/OpenGL/OpenGLRenderer.hpp"

#include "BrickEngine/Renderer/OpenGL/OpenGLVertexBuffer.hpp"
#include "BrickEngine/Renderer/OpenGL/OpenGLShader.hpp"

#if BRICKENGINE_PLATFORM_WINDOWS
	#include <GLFW/glfw3.h>
#endif

#include <glad/glad.h>

namespace BrickEngine {

	static void OpenGLMessageCallback(
		unsigned source,
		unsigned type,
		unsigned id,
		unsigned severity,
		int length,
		const char* message,
		const void* userParam)
	{
		switch (severity)
		{
		case GL_DEBUG_SEVERITY_HIGH:         BRICKENGINE_DEBUG_FATAL(message); return;
		case GL_DEBUG_SEVERITY_MEDIUM:       BRICKENGINE_DEBUG_ERROR(message); return;
		case GL_DEBUG_SEVERITY_LOW:          BRICKENGINE_DEBUG_WARN(message); return;
		case GL_DEBUG_SEVERITY_NOTIFICATION: BRICKENGINE_DEBUG_TRACE(message); return;
		}

		BRICKENGINE_ASSERT(false, "Unknown OpenGL severity level!");
	}

	OpenGLRenderer::OpenGLRenderer(Window* window)
		: m_Window(window)
	{
#if BRICKENGINE_PLATFORM_WINDOWS
		glfwMakeContextCurrent((GLFWwindow*)m_Window->GetNativeWindowHandle());
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
#endif
#if BRICKENGINE_ENABLE_DEBUG_LOGGING
		glEnable(GL_DEBUG_OUTPUT);
		glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
		glDebugMessageCallback(OpenGLMessageCallback, nullptr);

		glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, NULL, GL_FALSE);
#endif
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glEnable(GL_DEPTH_TEST);
	}

	OpenGLRenderer::~OpenGLRenderer()
	{
	}

	void OpenGLRenderer::SetClearColor(double red, double green, double blue, double alpha)
	{
		glClearColor((GLfloat)red, (GLfloat)green, (GLfloat)blue, (GLfloat)alpha);
	}

	void OpenGLRenderer::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	}

	void OpenGLRenderer::Draw(uint64 first, uint64 count)
	{
		glDrawArrays(GL_TRIANGLES, (GLint)first, (GLint)count);
	}

	void OpenGLRenderer::SwapBuffers()
	{
#if BRICKENGINE_PLATFORM_WINDOWS
		glfwSwapBuffers((GLFWwindow*)m_Window->GetNativeWindowHandle());
#endif
	}

	SharedPtr<Shader> OpenGLRenderer::CreateShader(const std::string& vertexSource, const std::string& fragmentSource)
	{
		return CreateShared<OpenGLShader>(vertexSource, fragmentSource);
	}

	SharedPtr<VertexBuffer> OpenGLRenderer::CreateVertexBuffer(const void* data, uint64 size, const VertexLayout& layout)
	{
		return CreateShared<OpenGLVertexBuffer>(data, size, layout);
	}

}
