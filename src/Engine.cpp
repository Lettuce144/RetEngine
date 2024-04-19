/*
* 
* Replacement for main. This will be executed inside of the main function.
* The header file also includes the loggers, and everthing else related to core engine functions.
* The platform code is not located here for obvious reasons. And thus is in a seperate file.
* (included here)
*/

#include "Engine.h"
#include "gl.hpp"

void RetEngine::LoadEngine()
{
}

void RetEngine::DestoryEngine()
{
	//destroy everything here
}


void RetEngine::PrintConsole(const char* message, MessageType messageType)
{
	std::string type;

	switch (messageType)
	{
	case MessageType::error:
		type = "[Error] ";
		break;
	case MessageType::warn:
		type = "[Warning] ";
		break;
	case MessageType::log:
		type = "[Log] ";
		break;
	default:
		std::cout << "Unknown messageType\n";
		break;
	}

	std::cout << std::chrono::system_clock::now() << type << message << "\n";

}