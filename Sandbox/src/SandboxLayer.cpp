#include "pch.hpp"
#include "SandboxLayer.hpp"

namespace Sandbox {

	void SandboxLayer::OnAttach()
	{
		m_Shader = m_Renderer.LoadShader("{WORKING_DIR}/Basic.vert.glsl", "{WORKING_DIR}/Basic.frag.glsl");

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
		m_Shader->SetVector4("u_Color", Vector4f(1.0f, 0.0f, 0.0f, 1.0f));
		m_VertexBuffer->Bind();
		m_Renderer.Draw(0, 3);
	}

}
