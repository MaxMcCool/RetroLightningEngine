#include "GameObject.h"
#include "Game.h"
#include "BaseComponent.h"
#include "TransformComponent.h"
GameObject::GameObject(float x, float y)
{
	XPosition = x;
	YPosition = y;
	XRotation = 0;
	YRotation = 0;
	sf::Transform xm = sf::Transform(x, 0.0f, 0.0f, 0.0f, y, 0.0f, 0.0f, 0.0f, 0.0f);
	
	transform = TransformComponent();
	
	transform.Translate(xm);
	componentList.push_back((BaseComponent)transform);
	sprite.setTexture(texture);
}

GameObject::GameObject(float x, float y, float angle)
{
	XPosition = x;
	YPosition = y;
	sf::Transform xm = sf::Transform(x, 0.0f, 0.0f, 0.0f, y, 0.0f, 0.0f, 0.0f, 0.0f);
	sf::Transform xmr = xm.rotate(angle);
	transform = TransformComponent();
	transform.Translate(xm);
	transform.Rotate(xmr);
	componentList.push_back((BaseComponent)transform);
	sprite.setTexture(texture);
}

void GameObject::Update()
{
	for (GameObject n : children)
	{
		n.Update();
	}
	for (BaseComponent m : componentList)
	{
		m.Update();
	}
}

void GameObject::Render()
{
	Game::mWindow.draw(sprite);
	if (children.size > 1) {
		for (GameObject n : children)
		{
			n.Render();
		}
	}
}

void GameObject::Attach(GameObject g)
{
	g.parent = this;
	children.push_back(g);
}

void GameObject::RemoveLast()
{
	children.pop_back();
}


sf::Transform GameObject::GetTransform()
{
	if (parent != NULL) {
		return transform.model.combine(parent->GetTransform());
	}
	else
	{
		return transform.model;
	}
}
