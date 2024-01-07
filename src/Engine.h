#pragma once

#include <iostream>

/// <summary>
/// Engine functions, like loading the engine and console printing.
/// </summary>
namespace RetEngine {

	#define PRINT_CONSOLE(message) std::cout << message << std::endl;

	void loadEngine();
}
