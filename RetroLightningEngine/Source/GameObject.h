#pragma once
#include <vector>
#include "BaseComponent.h"
#include "TransformComponent.h"
#include "PhysicsComponent.h"
#include "SFML\Graphics.hpp"
#include <string>

class GameObject {
public:
	float xSpeed = 5;
	float ySpeed = 0;
	float rotation = 0;
	GameObject() {};
	GameObject(float x, float y);
	GameObject(float x, float y, float angle);
	void Update();
	void Render();
	sf::Transform GetTransform();
	sf::Transform GetWorldTransform();
	sf::Transform xm;
	sf::Sprite sprite;
	void Move(float x, float y);
	void Attach(GameObject g);
	void RemoveLast();
	void Destroy();
	void Draw( sf::RenderWindow* window);
	PhysicsComponent mphysicsBody;
	sf::Sprite parent;
	bool hasParent;
	BaseComponent* components;
	float XPosition;
	float YPosition;
	sf::Texture texture;
	std::vector<GameObject> children;
};