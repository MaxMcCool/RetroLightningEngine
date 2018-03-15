#pragma once
#include <vector>
#include "BaseComponent.h"
#include "TransformComponent.h"
#include "SFML\Graphics.hpp"
class GameObject{
public:
	GameObject(float x, float y);
	GameObject(float x, float y, float angle);
	void Update();
	void Render();
	sf::Transform GetTransform();
	void Attach(GameObject g);
	void RemoveLast();
	TransformComponent transform;
	std::vector<GameObject> children;
	std::vector<BaseComponent> componentList;
	GameObject* parent;
	BaseComponent* components;
	
private:
	int XPosition;
	int YPosition;
	float XRotation;
	float YRotation;
	
	sf::Texture texture;
	sf::Sprite sprite;
};