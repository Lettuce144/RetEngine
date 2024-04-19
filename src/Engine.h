#pragma once

#include <iostream>
#include <chrono>

/// <summary>
/// Engine functions, like loading the engine and console printing.
/// </summary>
namespace RetEngine {

	enum class MessageType
	{
		error,
		warn,
		log, // This is too versatile, it basicly means everything that is not an error or a warning.
	};

	#define PRINT_CONSOLE(message, messageType) std::cout << message << std::endl;

	void LoadEngine();
	void DestoryEngine();
	void PrintConsole(const char* message, MessageType messageType);
}
