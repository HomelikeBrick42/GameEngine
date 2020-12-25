#include "brickpch.hpp"
#include "BrickEngine/Platform/WindowsWindow.hpp"

#ifdef BRICKENGINE_PLATFORM_WINDOWS

namespace BrickEngine {

    Window* Window::Create(uint32 width, uint32 height, const char* title, bool show)
    {
        return new WindowsWindow(width, height, title, show);
    }

    uint64 WindowsWindow::s_WindowCount = 0;

    WindowsWindow::WindowsWindow(uint32 width, uint32 height, const char* title, bool show)
    {
        if (s_WindowCount == 0)
        {
            int32 status = glfwInit();
            BRICKENGINE_ASSERT(status, "Unable to initalize GLFW!");
            glfwSetErrorCallback([](int32 error, const char* description) -> void
                {
                    std::cout << "GLFW Error: (" << error << "): '" << description << "'" << std::endl;
                });
        }
        s_WindowCount++;
        glfwWindowHint(GLFW_VISIBLE, show ? GLFW_TRUE : GLFW_FALSE);
        m_Window = glfwCreateWindow(width, height, title, nullptr, nullptr);
        BRICKENGINE_ASSERT(m_Window, "Unable to create GLFW window!");
    }

    WindowsWindow::~WindowsWindow()
    {
        glfwDestroyWindow(m_Window);
        s_WindowCount--;
        if (s_WindowCount == 0)
            glfwTerminate();
    }

    void WindowsWindow::Show()
    {
        glfwShowWindow(m_Window);
    }

    void WindowsWindow::Hide()
    {
        glfwHideWindow(m_Window);
    }

    void WindowsWindow::PollEvents()
    {
        glfwPollEvents();
    }

}

#endif
