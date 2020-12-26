#pragma once

#include <BrickEngine.hpp>

namespace Sandbox {

	using namespace BrickEngine;

	class SandboxLayer final : public Layer
	{
	public:
		SandboxLayer()
			: m_Renderer(Application::GetRenderer()) {}

		virtual void OnAttach() override final;
		virtual void OnDetach() override final;
		virtual void OnUpdate(float64 dt) override final;
		virtual void OnRender() override final;
	private:
		Renderer& m_Renderer;
		SharedPtr<VertexBuffer> m_VertexBuffer = nullptr;
		SharedPtr<Shader> m_Shader = nullptr;
	};

}
