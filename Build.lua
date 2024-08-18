-- premake5.lua
workspace "RetEngine"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "App"

   -- Workspace-wide build options for MSVC
   filter "system:windows"
      buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }

OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

group "Core"
	include "Core/Build-Core.lua"
   include "Renderer/Build-Render.lua"
group ""

include "App/Build-App.lua"

group "ThirdParty"
   include "thirdparty/Build-GLAD.lua"
   include "thirdparty/Build-GLFW.lua"
   include "thirdparty/Build-Imgui.lua"
   -- include "thirdparty/Build-GLM.lua"
   -- include "thirdparty/Build-Lua.lua"