#pragma once

#include "RetInclude.h"

//extern RetEngine::Application* RetEngine::CreateApplication();

int main(int argc, char** argv)
{
	std::cout << "Entrypoint call!" << std::endl;

	auto app = RetEngine::CreateApplication();
	//This should always loop
	app->Run();
	delete app;
}