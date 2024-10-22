project "Lua"
   kind "StaticLib"
   language "C"
   architecture "x86_64"

	targetdir ("../Binaries/" .. OutputDir .. "/%{prj.name}")
	objdir ("../Binaries/Intermediates/" .. OutputDir .. "/%{prj.name}")

   files
   {
      "lua/*.c",
      "lua/*.h"
   }

   filter "system:windows"
      systemversion "latest"
      staticruntime "On"

   filter "system:linux"
      pic "On"
      systemversion "latest"
      staticruntime "On"

   filter "configurations:Debug"
      runtime "Debug"
      symbols "On"

   filter "configurations:Release"
      runtime "Release"
      optimize "On"

   filter "configurations:Dist"
      runtime "Release"
      optimize "On"
