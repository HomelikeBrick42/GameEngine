#pragma once

#include "brickpch.hpp"

namespace BrickEngine {

	typedef unsigned char			uint8;
	typedef unsigned short			uint16;
	typedef unsigned int			uint32;
	typedef unsigned long long		uint64;

	typedef signed char				int8;
	typedef signed short			int16;
	typedef signed int				int32;
	typedef signed long long		int64;

	typedef float					float32;
	typedef double					float64;

	static_assert(sizeof(uint8) == 1, "Expected sizeof uint8 to be 1 byte.");
	static_assert(sizeof(uint16) == 2, "Expected sizeof uint16 to be 2 bytes.");
	static_assert(sizeof(uint32) == 4, "Expected sizeof uint32 to be 4 bytes.");
	static_assert(sizeof(uint64) == 8, "Expected sizeof uint64 to be 8 bytes.");

	static_assert(sizeof(int8) == 1, "Expected sizeof int8 to be 1 byte.");
	static_assert(sizeof(int16) == 2, "Expected sizeof int16 to be 2 bytes.");
	static_assert(sizeof(int32) == 4, "Expected sizeof int32 to be 4 bytes.");
	static_assert(sizeof(int64) == 8, "Expected sizeof int64 to be 8 bytes.");

	static_assert(sizeof(float32) == 4, "Expected sizeof float32 to be 4 bytes.");
	static_assert(sizeof(float64) == 8, "Expected sizeof float64 to be 8 bytes.");

	// TODO: Replace with own class
	template<typename T>
	using ScopePtr = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr ScopePtr<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	// TODO: Replace with own class
	template<typename T>
	using SharedPtr = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr SharedPtr<T> CreateShared(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}

#define BRICKENINE_BIND_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

#if defined(_WIN32) || defined(_WIN64)
	#define BRICKENGINE_PLATFORM_WINDOWS 1
#elif defined(__linux__)
	#define BRICKENGINE_PLATFORM_LINUX 1
#elif defined(__APPLE__)
	#define BRICKENGINE_PLATFORM_MAC 1
#endif

#if defined(BRICKENGINE_DLL)
	#if defined(BRICKENGINE_BUILD_DLL)
		#define BRICKENGINE_API __declspec(dllexport)
	#else
		#define BRICKENGINE_API __declspec(dllimport)
	#endif
#else
	#define BRICKENGINE_API
#endif

#define BRICKENGINE_ENABLE_ASSERTS 1
#if BRICKENGINE_ENABLE_ASSERTS
	#if defined(_MSC_VER)
		#include <intrin.h>
		#define BRICKENGINE_DEBUG_BREAK() __debugbreak()
	#else
		#define BRICKENGINE_DEBUG_BREAK()
	#endif
	#define BRICKENGINE_ASSERT(x, ...) if (!(x)) { BRICKENGINE_DEBUG_BREAK(); }
#else
	#define BRICKENGINE_ASSERT(x, ...)
#endif
