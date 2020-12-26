#pragma once

#include "BrickEngine/Core/Base.hpp"

namespace BrickEngine {

	class BRICKENGINE_API Platform
	{
	public:
		static void Init();
		static void Shutdown();

		static void InitTime();
		static float64 GetTime();
	private:
		Platform() = delete;
	};

}
