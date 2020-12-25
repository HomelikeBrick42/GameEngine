#include "brickpch.hpp"
#include "BrickEngine/Core/Application.hpp"

namespace BrickEngine {

	Application* Application::s_Application = nullptr;

	Application::Application()
	{
		BRICKENGINE_ASSERT(!s_Application, "Application already exists!");
		s_Application = this;

		m_Window = Window::Create(1280, 720, "BrickEngine Window", false);
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		m_Window->Show();
		while (m_Running)
		{
			m_Window->PollEvents();
		}
	}

}
