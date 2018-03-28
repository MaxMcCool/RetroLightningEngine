#pragma once
#include "BaseComponent.h"
#include <SFML\Graphics.hpp>

class PhysicsComponent : public BaseComponent{
public:
	PhysicsComponent();
	PhysicsComponent(sf::IntRect r);
	float xDir;
	float yDir;
	sf::IntRect boundingBox;
	void Collision();
	void update();
};