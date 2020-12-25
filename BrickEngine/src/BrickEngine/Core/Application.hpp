#pragma once

#include "BrickEngine/Core/Base.hpp"

#include "Window.hpp"

namespace BrickEngine {

	class Application
	{
	protected:
		Application();
	public:
		virtual ~Application();

		void Run();

		static Application& Get() { return *s_Application; }
	private:
		static Application* s_Application;
	private:
		bool m_Running = true;
		ScopePtr<Window> m_Window = nullptr;
	};

}
