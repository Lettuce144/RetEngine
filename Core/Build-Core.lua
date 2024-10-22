project "RetEngineCore"
   kind "StaticLib"
   language "C++"
   cppdialect "C++20"
   targetdir "Binaries/%{cfg.buildcfg}"

   files { "Source/**.h", "Source/**.cpp" }

   includedirs
   {
      "Source",
      "../thirdparty/*",
      "../thirdparty/glad/include",
      "../thirdparty/glfw/include",
      "../thirdparty/lua",
      "../Renderer/Source"
   }

   links { "Renderer", "ImGui", "GLFW", "Lua"}

   targetdir ("../Binaries/" .. OutputDir .. "/%{prj.name}")
   objdir ("../Binaries/Intermediates/" .. OutputDir .. "/%{prj.name}")

   filter "system:windows"
       systemversion "latest"
       defines { "WINDOWS" }

   filter "configurations:Debug"
       defines { "DEBUG" }
       runtime "Debug"
       symbols "On"

   filter "configurations:Release"
       defines { "RELEASE" }
       runtime "Release"
       optimize "On"
       symbols "On"

   filter "configurations:Dist"
       defines { "DIST" }
       runtime "Release"
       optimize "On"
       symbols "Off"
