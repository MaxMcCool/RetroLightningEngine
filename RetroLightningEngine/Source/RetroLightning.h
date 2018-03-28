#pragma once
#include "World.h"
#include <SFML\Graphics.hpp>
class RetroLightning {
public:
	RetroLightning();
	sf::RenderWindow* mWindow;
	World mWorld;
	void Run();
private:
	bool InitializeWorld();

};

