#include "TransformComponent.h"
#include <iostream>

TransformComponent::TransformComponent() {
	model = identity;
}
void TransformComponent::Update(sf::Transform xm) 
{
	model = xm;
}
void TransformComponent::move(float x, float y)
{
	model.translate(x, y);
}