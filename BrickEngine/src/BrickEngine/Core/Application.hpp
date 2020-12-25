#pragma once

#include "BrickEngine/Core/Base.hpp"

#include "BrickEngine/Core/Window.hpp"
#include "BrickEngine/Core/Layer.hpp"

namespace BrickEngine {

	class Application
	{
	protected:
		Application();
	public:
		virtual ~Application();

		void Run();

		static Application& Get() { return *s_Application; }
		static Window& GetWindow() { return *s_Application->m_Window; }

		void PushLayer(Layer* layer);
	private:
		static Application* s_Application;
	private:
		bool m_Running = true;
		ScopePtr<Window> m_Window = nullptr;
		std::vector<Layer*> m_Layers = {};
	};

}
