#include "EngineInitialization.h"

#include "Game.h"
#include "World.h"
#include <cassert>

Game::Game()
{
	if (InitializeWorld()) {
		Run();
	}
}

bool Game::InitializeWorld()
{

	//Splash Screen
	sf::Texture texture;
	/*assert(*/texture.loadFromFile("..\Assets\Logo.png")/*)*/;
	sf::Sprite splashLogo;
	splashLogo.setTexture(texture);
	splashLogo.setPosition(1024.0f / 2.0f, 769.0f / 2.0f);
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


	return hasRequirementsMet;
}

void Game::Run()
{
	
	mWindow.setTitle("RetroLightningGame");
	mWindow.setSize({ 1024,769 });

	while (mWindow.isOpen())
	{
		//Game::mWindow
		//update input
			// inputManager::Update;
		
		//update physics
			// PhysicsManager::Update;

		//update gameobjects
			//World.update;

		//update AI
			//AI.update;

		//update 
		/*sf::Event event;
		while (mWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				mWindow.close();
			}	
		}*/

		mWindow.clear();
		mWindow.display();

		// Play Audio
	}

}
