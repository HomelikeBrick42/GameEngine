#pragma once

#include "BrickEngine/Core/Window.hpp"

#ifdef BRICKENGINE_PLATFORM_WINDOWS

#include <GLFW/glfw3.h>

namespace BrickEngine {

	class WindowsWindow final : public Window
	{
	public:
		WindowsWindow(uint32 width, uint32 height, const char* title, bool show);
		~WindowsWindow();

		virtual void Show() override final;
		virtual void Hide() override final;

		virtual void PollEvents() override final;
	private:
		static uint64 s_WindowCount;
	private:
		GLFWwindow* m_Window = nullptr;
	};

}

#endif
