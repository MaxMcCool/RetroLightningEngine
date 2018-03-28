#include "PhysicsHandler.h"

PhysicsHandler::PhysicsHandler()
{

}

void PhysicsHandler::checkForCollisions()
{
	std::vector<PhysicsComponent>::iterator it;
	std::vector<PhysicsComponent>::iterator it2;
	for (it = physicsObjects.begin(); it != physicsObjects.end(); it++)
	{
		for (it2 = physicsObjects.begin(); it2 != physicsObjects.end(); it2++)
		{
			if (it->boundingBox.intersects(it2->boundingBox))
			{
				resolveCollisions(*it, *it2);
			}
		}
	}
	physicsObjects.empty();
}

void PhysicsHandler::resolveCollisions(PhysicsComponent obj1, PhysicsComponent obj2)
{
	obj1.Collision();
	obj2.Collision();
}

void PhysicsHandler::Update()
{
	
	
}