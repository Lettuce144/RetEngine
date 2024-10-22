#pragma once
#include <iostream>

class LuaPrint
{
public:
	LuaPrint(const std::string& name);
	~LuaPrint();

	void SayHi();
	void SayString(const std::string& text);
	const std::string& GetName() const;

private:
	std::string m_sName;
};
