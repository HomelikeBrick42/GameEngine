#pragma once

namespace BrickEngine {

	class Log
	{
	public:
		static void Trace(const char* fmt, ...);
		static void Info(const char* fmt, ...);
		static void Warn(const char* fmt, ...);
		static void Error(const char* fmt, ...);
		static void Fatal(const char* fmt, ...);
	private:
		Log() = delete;
	};

}
