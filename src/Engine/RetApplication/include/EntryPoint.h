#pragma once

#include "RetInclude.h"

//extern RetEngine::Application* RetEngine::CreateApplication();

int main(int argc, char** argv)
{
	std::cout << "Hello world!" << std::endl;

	auto app = RetEngine::CreateApplication();
	app->Run();
	delete app;
}