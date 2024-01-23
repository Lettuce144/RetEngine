#pragma once

#ifdef RETENGINE_APP_DLL_PROJECT
#define RETENGINE_APPLICATION __declspec(dllexport)
#else // RETENGINE_APP_DLL_PROJECT
#define RETENGINE_APPLICATION __declspec(dllimport)
#endif

namespace RetEngine {



	class RETENGINE_APPLICATION Application
	{
	public:
		Application();
		~Application();

		void Run();

	private:

	};


	Application* CreateApplication();


}