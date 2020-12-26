#include "brickpch.hpp"
#include "BrickEngine/Core/Application.hpp"

#include "BrickEngine/Core/Platform.hpp"

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
