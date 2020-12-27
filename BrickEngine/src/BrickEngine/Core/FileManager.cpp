#include "brickpch.hpp"
#include "BrickEngine/Core/FileManager.hpp"

#include "BrickEngine/Core/Platform.hpp"

#include <fstream>
#include <filesystem>
#include <sstream>

namespace BrickEngine {

    static void Replace(std::string& string, const std::string& find, const std::string replace)
    {
        size_t pos = 0;
        while ((pos = string.find(find, pos)) != std::string::npos) {
            string.replace(pos, find.length(), replace);
            pos += replace.length();
        }
    }

    std::string FileManager::LoadString(const std::string& filepath)
    {
        std::string exePath = Platform::GetExecutablePath();
        std::string path(filepath);

        Replace(path, "{EXE_PATH}", exePath);
        Replace(path, "{WORKING_DIR}", std::filesystem::current_path().string());
        Replace(path, "\\", "/");

        std::ifstream in(path);
        if (!in.is_open())
        {
            Log::Error("Failed to load file '%s'", path.c_str());
            return "";
        }

        std::stringstream ss;
        ss << in.rdbuf();
        in.close();
        return ss.str();
    }

}
