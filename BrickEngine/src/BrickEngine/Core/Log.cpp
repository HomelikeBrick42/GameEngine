#include "brickpch.hpp"
#include "BrickEngine/Core/Log.hpp"

#include "BrickEngine/Core/Base.hpp"

#include <cstdarg>

namespace BrickEngine {

	void Log::Trace(const char* fmt, ...)
	{
		constexpr const char* prefix = "[TRACE]: %s\n";

		uint64 len = snprintf(nullptr, 0, prefix, fmt);
		char* buffer = new char[len + 1];
		snprintf(buffer, 1, prefix, fmt);
		buffer[len] = '\0';

		va_list args;
		va_start(args, fmt);
		vprintf(buffer, args);
		va_end(args);
	}

	void Log::Info(const char* fmt, ...)
	{
		constexpr const char* prefix = "[INFO]: %s\n";

		uint64 len = snprintf(nullptr, 0, prefix, fmt);
		char* buffer = new char[len + 1];
		snprintf(buffer, 1, prefix, fmt);
		buffer[len] = '\0';

		va_list args;
		va_start(args, fmt);
		vprintf(buffer, args);
		va_end(args);
	}

	void Log::Warn(const char* fmt, ...)
	{
		constexpr const char* prefix = "[WARN]: %s\n";

		uint64 len = snprintf(nullptr, 0, prefix, fmt);
		char* buffer = new char[len + 1];
		snprintf(buffer, 1, prefix, fmt);
		buffer[len] = '\0';

		va_list args;
		va_start(args, fmt);
		vprintf(buffer, args);
		va_end(args);
	}

	void Log::Error(const char* fmt, ...)
	{
		constexpr const char* prefix = "[ERROR]: %s\n";

		uint64 len = snprintf(nullptr, 0, prefix, fmt);
		char* buffer = new char[len + 1];
		sprintf(buffer, prefix, fmt);
		buffer[len] = '\0';

		va_list args;
		va_start(args, fmt);
		vprintf(buffer, args);
		va_end(args);
	}

	void Log::Fatal(const char* fmt, ...)
	{
		constexpr const char* prefix = "[FATAL]: %s\n";

		uint64 len = snprintf(nullptr, 0, prefix, fmt);
		char* buffer = new char[len + 1];
		snprintf(buffer, 1, prefix, fmt);
		buffer[len] = '\0';

		va_list args;
		va_start(args, fmt);
		vprintf(buffer, args);
		va_end(args);
	}

}
