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
	sf::Vector2<float> bulletStart;
	int bulletcounter = 0;
	float playeraccelx = 0;
	float playeraccely = 0;
	float boxaccelx = 0;
	float boxaccely = 0;
	float childaccelx = 0;
	float childaccely = 0;
	float bulletspeed = -5;
	float enemybulletspeed = 3;
	sf::Texture bullet;
	sf::Texture ebullet;
	sf::Sprite pbullet[10];
	sf::Sprite ebullets[10];
	bool pbIsFiring[10];
	bool ebIsFiring[10];
	sf::Sprite background;
	sf::Texture bg;
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