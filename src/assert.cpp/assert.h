#pragma once
#include <iostream>

#define Assert(condition, message) if(condition == false) do_assert(message, __LINE__, __func__, __FILE__)

void do_assert(const char* message, int line, const char* func, const char* file)
{
	//Todo: use the logging system here
    std::cout << 
        "ASSERTION FAILED: \n" <<
        "Message: " << message << "\n" <<
        "Line: " << line << "\n" <<
        "Function: " << func << "\n" <<
        "File: " << file << "\n";
}