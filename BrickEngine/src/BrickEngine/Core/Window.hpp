#pragma once

#include "BrickEngine/Core/Base.hpp"

namespace BrickEngine {

	class BRICKENGINE_API Window
	{
	public:
		virtual ~Window() = default;

		virtual void Show() = 0;
		virtual void Hide() = 0;

		virtual void PollEvents() = 0;

		virtual void* GetNativeWindowHandle() = 0;

		static ScopePtr<Window> Create(uint32 width, uint32 height, const char* title, bool show = true);
	protected:
		Window() = default;
	private:
		Window(const Window&) = delete;
		Window& operator=(const Window&) = delete;
	};

}
