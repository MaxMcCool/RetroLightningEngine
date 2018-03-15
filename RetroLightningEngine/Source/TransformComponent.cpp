#include "TransformComponent.h"

TransformComponent::TransformComponent() {
	model = sf::Transform();
}

TransformComponent::TransformComponent(sf::Transform xm)
{
	model = xm;
}

void TransformComponent::Translate(sf::Transform xm)
{
	positionM = xm;
}

void TransformComponent::Rotate(sf::Transform xm)
{
	rotationM = xm;
}

void TransformComponent::Scale(float scale)
{
	scaleM = sf::Transform().scale(scale, scale);
}

void TransformComponent::Update()
{
	model = model.combine(positionM).combine(rotationM).combine(scaleM);
}