// Example class for using lua bindings

#include "catclass.h"

LuaPrint::LuaPrint(const std::string& name) : m_sName(name)
{
}

LuaPrint::~LuaPrint()
{
}


void LuaPrint::SayHi()
{
	std::cout << "Hello world! -Cpp" << std::endl;
}

void LuaPrint::SayString(const std::string& text)
{
	std::cout << text << std::endl;
}

const std::string& LuaPrint::GetName() const
{
	return m_sName;
}