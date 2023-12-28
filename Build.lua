-- premake5.lua
workspace "Physics Engine"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "Render"

   -- Workspace-wide build options for MSVC
   filter "system:windows"
      buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }

OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

group "Engine"
	include "Engine/Build-Engine.lua"
group ""

include "Render/Build-Render.lua"