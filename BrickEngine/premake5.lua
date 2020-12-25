project "BrickEngine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	
	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "brickpch.hpp"
	pchsource "src/brickpch.cpp"
	
	files
	{
		"src/**.hpp",
		"src/**.cpp"
	}
	
	includedirs
	{
		"src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}"
	}
	
	links
	{
		"opengl32.lib",
		"GLFW",
		"Glad"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "BRICKENGINE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "BRICKENGINE_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "BRICKENGINE_DIST"
		runtime "Release"
        optimize "on"
