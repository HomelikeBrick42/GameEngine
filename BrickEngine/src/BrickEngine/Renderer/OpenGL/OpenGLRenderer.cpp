#include "brickpch.hpp"
#include "BrickEngine/Renderer/OpenGL/OpenGLRenderer.hpp"

#include "BrickEngine/Renderer/OpenGL/OpenGLVertexBuffer.hpp"

#if BRICKENGINE_PLATFORM_WINDOWS
	#include <GLFW/glfw3.h>
#endif

#include <glad/glad.h>

namespace BrickEngine {

	OpenGLRenderer::OpenGLRenderer(Window* window)
		: m_Window(window)
	{
#if BRICKENGINE_PLATFORM_WINDOWS
		glfwMakeContextCurrent((GLFWwindow*)m_Window->GetNativeWindowHandle());
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
#endif
	}

	OpenGLRenderer::~OpenGLRenderer()
	{
	}

	void OpenGLRenderer::SwapBuffers()
	{
#if BRICKENGINE_PLATFORM_WINDOWS
		glfwSwapBuffers((GLFWwindow*)m_Window->GetNativeWindowHandle());
#endif
	}

	SharedPtr<VertexBuffer> OpenGLRenderer::CreateVertexBuffer(const void* data, uint64 size, const VertexLayout& layout)
	{
		return CreateShared<OpenGLVertexBuffer>(data, size, layout);
	}

}
