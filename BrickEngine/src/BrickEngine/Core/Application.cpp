#include "brickpch.hpp"
#include "BrickEngine/Core/Application.hpp"

#include "BrickEngine/Core/Platform.hpp"

#include "BrickEngine/Renderer/VertexBuffer.hpp"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace BrickEngine {

	Application* Application::s_Application = nullptr;

	Application::Application()
	{
		BRICKENGINE_ASSERT(!s_Application, "Application already exists!");
		s_Application = this;

		Platform::Init();
		Platform::InitTime();
		m_Window = Window::Create(1280, 720, "BrickEngine Window", false);
	}

	Application::~Application()
	{
		for (auto& layer : m_Layers)
		{
			layer->OnDetach();
			delete layer;
		}
		Platform::Shutdown();
	}

	void Application::Run()
	{
		m_Window->Show();

		glfwMakeContextCurrent((GLFWwindow*)m_Window->GetNativeWindowHandle());
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

		GLuint vertexArray;
		glGenVertexArrays(1, &vertexArray);
		glBindVertexArray(vertexArray);

		float vertices[] = {
			 0.0f,  0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			-0.5f, -0.5f, 0.0f
		};
		SharedPtr<VertexBuffer> vertexBuffer = VertexBuffer::Create(vertices, 9 * sizeof(float));
		vertexBuffer->Bind();

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (const void*)0);

		double delta, time, lastTime = Platform::GetTime();
		while (m_Running)
		{
			time = Platform::GetTime();
			delta = time - lastTime;
			lastTime = time;

			for (auto& layer : m_Layers)
				layer->OnUpdate(delta);
			for (auto& layer : m_Layers)
				layer->OnRender();

			glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

			vertexBuffer->Bind();
			glDrawArrays(GL_TRIANGLES, 0, 3);

			m_Window->PollEvents();
			glfwSwapBuffers((GLFWwindow*)m_Window->GetNativeWindowHandle());
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_Layers.push_back(layer);
		layer->OnAttach();
	}

}
