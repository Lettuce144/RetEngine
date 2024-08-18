project "ImGui"
	kind "StaticLib"
	language "C++"

	targetdir "Binaries/%{cfg.buildcfg}"
	objdir "../obj/%{cfg.buildcfg}"

	includedirs
	{
		"imgui/",
		"glfw/include"
	}

	links { "GLFW" }

	files
	{
		"imgui/imgui.cpp",
		"imgui/imgui_draw.cpp",
		"imgui/imgui_widgets.cpp",
		"imgui/imgui_demo.cpp",
		"imgui/backends/imgui_impl_glfw.cpp",
		"imgui/backends/imgui_impl_opengl3.cpp"
	}

	filter "system:windows"
		systemversion "latest"
		cppdialect "C++20"
		staticruntime "On"

	filter "system:linux"
		pic "On"
		systemversion "latest"
		cppdialect "C++20"
		staticruntime "On"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"