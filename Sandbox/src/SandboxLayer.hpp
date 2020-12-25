#pragma once

#include <BrickEngine.hpp>

namespace Sandbox {

	using namespace BrickEngine;

	class SandboxLayer final : public Layer
	{
	public:
		virtual void OnAttach() override final;
		virtual void OnDetach() override final;
		virtual void OnUpdate(float64 dt) override final;
		virtual void OnRender() override final;
	};

}
