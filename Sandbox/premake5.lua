project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	
	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "pch.hpp"
	pchsource "src/pch.cpp"

	files
	{
		"src/**.hpp",
		"src/**.cpp"
	}
	
	includedirs
	{
		"src",
		"%{wks.location}/BrickEngine/src"
	}

	links
	{
		"BrickEngine"
	}

	defines
	{
	}

	filter "system:windows"
		systemversion "latest"

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
