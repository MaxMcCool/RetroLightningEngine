#pragma once
#include "World.h"
class Game {
public:
	Game();
	void Run();
	sf::RenderWindow mWindow;
private:
	void InitializeWorld();
	World mWorld;
	

};