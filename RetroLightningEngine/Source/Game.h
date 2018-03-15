#pragma once
#include "World.h"
#include <SFML\Graphics.hpp>
class Game {
public:
	Game();
	void Run();
private:
	bool InitializeWorld();

	static World mWorld;
public:
	static sf::RenderWindow mWindow;

};