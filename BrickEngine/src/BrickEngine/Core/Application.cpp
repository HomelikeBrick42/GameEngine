#include "brickpch.hpp"
#include "BrickEngine/Core/Application.hpp"

#include "BrickEngine/Core/Platform.hpp"

#include "BrickEngine/Renderer/VertexBuffer.hpp"

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
		m_Renderer = Renderer::Create(m_Window.get());
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

		float vertices[] = {
			 0.0f,  0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
			 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
			-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f
		};
		SharedPtr<VertexBuffer> vertexBuffer = m_Renderer->CreateVertexBuffer(vertices, sizeof(vertices), {
			{ ShaderDataType::Float3, "a_Position" },
			{ ShaderDataType::Float4, "a_Color"    }
		});

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

			m_Renderer->SetClearColor(0.1, 0.1, 0.1, 1.0);
			m_Renderer->Clear();

			vertexBuffer->Bind();
			m_Renderer->Draw(0, 3);

			m_Window->PollEvents();
			m_Renderer->SwapBuffers();
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_Layers.push_back(layer);
		layer->OnAttach();
	}

}
