#include "GameObject.h"
#include "RetroLightning.h"
#include "BaseComponent.h"
#include "TransformComponent.h"
#include "PhysicsHandler.h"
#include <iostream>
GameObject::GameObject(float x, float y)
{
	XPosition = x;
	YPosition = y;
	sprite = sf::Sprite();
	sprite.setPosition(x, y);
	texture.loadFromFile("Assets/Eagle.png");
	sprite.setTexture(texture);
	
}


GameObject::GameObject(float x, float y, float angle)
{
	XPosition = x;
	YPosition = y;

	texture.loadFromFile("Assets/Eagle.png");
	sprite.setTexture(texture);
	
}

GameObject::GameObject(float x, float y, float xspeed, float yspeed)
{
	XPosition = x;
	YPosition = y;
	xSpeed = xspeed;
	ySpeed = yspeed;
	texture.loadFromFile("Assets/Eagle.png");
	sprite.setTexture(texture);
}

void GameObject::Update()
{
}

void GameObject::Render()
{
	if (children.size() > 1) {
		for (GameObject n : children)
		{
			n.Render();
		}
	}
}

void GameObject::Attach(GameObject g)
{
	g.parent = this->sprite;
	g.hasParent = true;
	children.push_back(g);
}

void GameObject::RemoveLast()
{
	children.pop_back();
}


sf::Transform GameObject::GetTransform()
{
	return xm;
}
void GameObject::Destroy()
{

}

sf::Transform GameObject::GetWorldTransform()
{
	if (hasParent)
	{
		
		return parent.getTransform() * sprite.getTransform();
	}
	else {
		
		return sprite.getTransform();

	}
}
void GameObject::Draw( sf::RenderWindow* window)
{
	sprite.setTexture(texture);
	//
	YPosition = YPosition - ySpeed;
	sprite.setPosition(XPosition, YPosition);
	window->draw(sprite);
	window->display();
	if (children.size() > 0)
	{
		for (GameObject n : children)
		{
			n.Draw(window);
		}
	}
}

void GameObject::Move(float x, float y)
{
	sprite.setPosition(x, y);
}
void GameObject::setSpeed(float x, float y)
{
	xSpeed = x;
	ySpeed = y;
}
float GameObject::getXSpeed()
{
	return xSpeed;
}
float GameObject::getYSpeed()
{
	return ySpeed;
}
sf::Sprite* GameObject::getSprite()
{
	return &sprite;
}
