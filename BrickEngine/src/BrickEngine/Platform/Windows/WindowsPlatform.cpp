#include "brickpch.hpp"
#include "BrickEngine/Core/Platform.hpp"

#if BRICKENGINE_PLATFORM_WINDOWS

#include <Windows.h>

namespace BrickEngine {

	struct PlatformData
	{
		LARGE_INTEGER Frequency;
	};
	static PlatformData* s_Data = nullptr;

	void Platform::Init()
	{
		s_Data = new PlatformData();
	}

	void Platform::Shutdown()
	{
		delete s_Data;
	}

	void Platform::InitTime()
	{
		BOOL success = QueryPerformanceFrequency(&s_Data->Frequency);
		BRICKENGINE_ASSERT(success, "Windows Error: Unable to get preformance frequency.");
	}

	float64 Platform::GetTime()
	{
		static LARGE_INTEGER counter;
		BOOL success = QueryPerformanceCounter(&counter);
		BRICKENGINE_ASSERT(success, "Windows Error: Unable to get preformance counter.");
		return (float64)counter.QuadPart / (float64)s_Data->Frequency.QuadPart;
	}

}

#endif
