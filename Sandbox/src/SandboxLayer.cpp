#include "pch.hpp"
#include "SandboxLayer.hpp"

namespace Sandbox {

	void SandboxLayer::OnAttach()
	{
		m_Shader = m_Renderer.CreateShader(
R"(
#version 440 core

layout(location = 0) in vec4 a_Position;

void main()
{
	gl_Position = a_Position;
}
)",

R"(
#version 440 core

layout(location = 0) out vec4 o_Color;

void main()
{
	o_Color = vec4(1.0, 0.0, 0.0, 1.0);
}
)");

		std::vector<float> vertices = {
			0.0f,  0.5f, 0.0f,
			0.5f, -0.5f, 0.0f,
		   -0.5f, -0.5f, 0.0f
		};
		m_VertexBuffer = m_Renderer.CreateVertexBuffer(vertices.data(), vertices.size() * sizeof(float), {
			{ ShaderDataType::Float3, "a_Position" }
		});
	}

	void SandboxLayer::OnDetach()
	{
	}

	void SandboxLayer::OnUpdate(float64 dt)
	{
	}

	void SandboxLayer::OnRender()
	{
		m_Renderer.SetClearColor(0.1, 0.1, 0.1, 1.0);
		m_Renderer.Clear();

		m_Shader->Bind();
		m_VertexBuffer->Bind();
		m_Renderer.Draw(0, 3);
	}

}
