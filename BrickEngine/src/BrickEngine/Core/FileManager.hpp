#pragma once

#include "BrickEngine/Core/Base.hpp"

namespace BrickEngine {

	class BRICKENGINE_API FileManager
	{
	public:
		/// <summary>
		/// Loads a file as text.
		/// Tokens:
		///		{EXE_PATH}:		The path to the exe
		///		{WORKING_DIR}:	The current working directory
		/// </summary>
		static std::string LoadString(const std::string& filepath);
	private:
		FileManager() = delete;
	};

}
