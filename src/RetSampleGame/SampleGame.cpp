#include <iostream>
#include <RetInclude.h>

class SampleGame : public RetEngine::Application
{
public:
	SampleGame();
	~SampleGame();

private:

};

SampleGame::SampleGame()
{
}

SampleGame::~SampleGame()
{
}

RetEngine::Application* RetEngine::CreateApplication()
{
	return new SampleGame();
}