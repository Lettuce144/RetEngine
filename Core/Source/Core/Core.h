#pragma once
#ifndef CORE_H
#include <iostream>

#if WINDOWS
	#include <Windows.h>
#endif // WINDOWS

namespace RetEngine::Core {
	void Run(const std::string& applicationName);
}
#endif // !CORE_H