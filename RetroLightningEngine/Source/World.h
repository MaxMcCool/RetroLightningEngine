#pragma once
#include "SceneGraph.h"
#include "SFML\Graphics.hpp"
#include "PhysicsHandler.h"
class World {
public:
	float counter = 0;
	sf::Texture boxtex;
	GameObject player;
	GameObject box;
	float playeraccelx = 0;
	float playeraccely = 0;
	float boxaccelx = 0;
	float boxaccely = 0;
	float childaccelx = 0;
	float childaccely = 0;
	World();
	float gravity = 2;
	World(sf::RenderWindow* window);
	void handleEvent(sf::Event e);
	void Update();
	void BuildWorld();
	void display();
	bool IsOpen();
	sf::RenderWindow* mRenderWindow;
	static std::vector<GameObject> masterObjectList;
private:
	SceneGraph mSceneGraph;
	sf::Transform test;
	sf::Texture testtex;
	sf::Sprite textspr;
};