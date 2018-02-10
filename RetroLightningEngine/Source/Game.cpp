#include "EngineInitialization.h"
#include "Game.h"
#include "World.h"
#include <cassert>

Game::Game()
{
	InitializeWorld();
}

void Game::InitializeWorld()
{
	mWindow.setSize({ 1024,769 });
	mWindow.setTitle("RetroLightning");

	//Splash Screen
	sf::Texture texture;
	/*assert(*/texture.loadFromFile("Logo.png")/*)*/;
	sf::Sprite splashLogo;
	splashLogo.setTexture(texture);
	sf::RenderWindow splash({ 1024,769 }, "RetroLightning");
	splash.draw(splashLogo);
	splash.display();

	//Check System requirements
	bool hasRequirementsMet = true;
	LPCTSTR Title = "RetroLightningEngine";
	if (!IsOnlyInstance(Title))
	{
		//error
		hasRequirementsMet = false;
	}
	DWORDLONG SpaceNeeded = 300000000;
	if (!CheckStorage(SpaceNeeded))
	{
		//error
		hasRequirementsMet = false;
	}
	DWORDLONG RAMNeeded = 300000000;
	DWORDLONG VRAMNeeded = 300000000;
	if (!CheckMemory(RAMNeeded, VRAMNeeded))
	{
		//error
		hasRequirementsMet = false;
	}

	DWORD Success = ReadCPUSpeed();

	//Create World

	



	if (hasRequirementsMet)
	{
		
		mWorld = World(&sf::RenderWindow({ 1024,769 },"RetroLightning"));
	}


}

void Game::Run()
{
	
	while (mWorld.IsOpen())
	{
		sf::Event event;
		while (mWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
			}	//mWorld.mRenderWindow->close();
		}

		mWindow.clear();
		mWorld.display();
	}

}
