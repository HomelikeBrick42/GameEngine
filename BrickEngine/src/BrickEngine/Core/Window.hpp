#pragma once

#include "BrickEngine/Core/Base.hpp"

namespace BrickEngine {

	class BRICKENGINE_API Window
	{
	public:
		virtual ~Window() = default;

		virtual void PollEvents() = 0;

		static Window* Create(uint32 width, uint32 height, const char* title);
	protected:
		Window() = default;
	private:
		Window(const Window&) = delete;
		Window& operator=(const Window&) = delete;
	};

}
