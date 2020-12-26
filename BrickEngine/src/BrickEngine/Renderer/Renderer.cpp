#include "brickpch.hpp"
#include "BrickEngine/Renderer/Renderer.hpp"

#include "BrickEngine/Renderer/OpenGL/OpenGLRenderer.hpp"

namespace BrickEngine {

    ScopePtr<Renderer> Renderer::Create(Window* window)
    {
        return CreateScope<OpenGLRenderer>(window);
    }

}
