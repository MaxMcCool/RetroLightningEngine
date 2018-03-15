#pragma once
#include "BaseComponent.h"
#include <Windows.h>
#include <DirectXMath.h>
#include <SFML\Graphics.hpp>
class TransformComponent : public BaseComponent {
public:
	sf::Transform model;
	sf::Transform positionM;
	sf::Transform rotationM;
	sf::Transform scaleM;
	sf::Transform g;
	TransformComponent();
	TransformComponent(sf::Transform xm);
	void Translate(sf::Transform xm);
	void Rotate(sf::Transform xm);
	void Scale(float scale);
	void Update();
};


