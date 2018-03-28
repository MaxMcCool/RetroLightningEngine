#include "PhysicsComponent.h"
#include "PhysicsHandler.h"
#include <SFML\Graphics.hpp>

PhysicsComponent::PhysicsComponent()
{

}
PhysicsComponent::PhysicsComponent(sf::IntRect r)
{
	boundingBox = r;
}

void PhysicsComponent::Collision()
{
	//either destroy or move
	//demo change color and move
}
void PhysicsComponent::update()
{
	//call this first
	
}