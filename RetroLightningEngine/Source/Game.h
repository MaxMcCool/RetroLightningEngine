#pragma once
#include "World.h"
class Game {
public:
	Game();
	void Run();
private:
	void InitializeWorld();
	World mWorld;
	

};