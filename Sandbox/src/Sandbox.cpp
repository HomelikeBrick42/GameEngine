#include "pch.hpp"
#include "Sandbox.hpp"

#include "SandboxLayer.hpp"

namespace Sandbox {

	using namespace BrickEngine;

	Sandbox::Sandbox()
	{
		PushLayer(new SandboxLayer());
	}

	Sandbox::~Sandbox()
	{
	}

}
