#include "Core.h"
#include <sstream>
#include <fstream>
#include "catclass.h"
#include "Window.h"
//TODO: Move window to seperate class

// Libs
#include "luaaa.hpp"

#define HEIGHT 600
#define WIDTH 800

namespace RetEngine::Core {

	lua_State* global_state;
	Window* window;

	//Register the lua bindings
	void InitiateLua(lua_State* ls)
	{
		luaaa::LuaClass<LuaPrint> luaPrint(ls, "LC_LuaClass");
		luaPrint.ctor<std::string>();
		luaPrint.fun("SayString", &LuaPrint::SayString);
		luaPrint.get("Name", &LuaPrint::GetName);

		luaaa::LuaModule windowModule(global_state, "Window");
		// We have to use a lamdba for some reason, this is related to luaaa
		windowModule.fun("IsOpen", []() {return window->IsOpen(); });

	}

	void ExecuteDemoLua(lua_State* state)
	{
		InitiateLua(state);

		std::stringstream buffer;
		std::ifstream file("C:/Users/jelge/Documents/ProjectsLocal/RetEngine/Binaries/windows-x86_64/Debug/App/default.lua");
		
		if (file)
		{
			buffer << file.rdbuf();
			file.close();
		}
		else
		{
			std::cerr << "Failed to open default.lua\n";
			return;
		}

		int err = luaL_loadbuffer(state, buffer.str().c_str(), buffer.str().length(), "console");
		if (err == 0)
		{
			err = lua_pcall(state, 0, 0, 0);
		}

		if (err)
		{
			lua_pop(state, 1);
		}
	}

	// Render loop is called here
	void Run(const std::string& applicationName)
	{
		window = new Window(applicationName, HEIGHT, WIDTH);

		Renderer* render = new Renderer();
		render->RenderInit(WIDTH, HEIGHT);

		//Setup Lua
		global_state = luaL_newstate();
		luaL_openlibs(global_state);

		if (global_state != NULL)
		{
			ExecuteDemoLua(global_state);
			lua_close(global_state);
		}

		//Loop
		render->Render(window->GetWindow());


		glfwTerminate();
		delete render;
		delete window;
		return;
	}



}