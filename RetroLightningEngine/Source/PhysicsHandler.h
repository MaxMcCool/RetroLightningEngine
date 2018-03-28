#pragma once
#include "PhysicsComponent.h"
#include "GameObject.h"
#include "SFML\Graphics.hpp"
#include <vector>
class PhysicsHandler
{
public:
	PhysicsHandler();
	std::vector<PhysicsComponent> physicsObjects;
	void checkForCollisions();
	void resolveCollisions(PhysicsComponent obj1, PhysicsComponent obj2);
	void Update();
};