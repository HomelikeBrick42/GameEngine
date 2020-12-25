workspace "GameEngineTest1"
architecture "x64"
startproject "Sandbox"

configurations
{
    "Debug",
    "Release",
    "Dist"
}

flags
{
    "MultiProcessorCompile"
}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/BrickEngine/vendor/GLFW/glfw/include"
IncludeDir["Glad"] = "%{wks.location}/BrickEngine/vendor/Glad/glad/include"

group "Dependencies"
    include "BrickEngine/vendor/GLFW"
    include "BrickEngine/vendor/Glad"
group ""

include "BrickEngine"
include "Sandbox"
