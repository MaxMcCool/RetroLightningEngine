#pragma once
#include "BaseComponent.h"
#include <Windows.h>
#include <DirectXMath.h>
#include <SFML\Graphics.hpp>
class TransformComponent : public BaseComponent {
public:
	sf::Transform model;
	TransformComponent();
	void move(float x, float y);
	void Update(sf::Transform xm);
	sf::Transform identity = sf::Transform(1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
};


