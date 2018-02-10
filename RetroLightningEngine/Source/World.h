#pragma once
#include "SceneGraph.h"
#include "SFML\Graphics.hpp"
class World {
public:
	World();
	World(sf::RenderWindow* window);
	void Update();
	void Render();
	void BuildWorld();
	void display();
	bool IsOpen();
	sf::RenderWindow* mRenderWindow;
private:
	SceneGraph mSceneGraph;
	
};