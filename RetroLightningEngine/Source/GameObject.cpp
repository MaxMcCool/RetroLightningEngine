#include "GameObject.h"

GameObject::GameObject(int x, int y)
{
	XPosition = x;
	YPosition = y;
	XRotation = 0;
	YRotation = 0;
}

GameObject::GameObject(int x, int y, float rotx, float roty)
{
	XPosition = x;
	YPosition = y;
	XRotation = rotx;
	YRotation = roty;
}

void GameObject::Update()
{
	for (GameObject n : children)
	{
		n.Update();
	}
}

void GameObject::Render()
{
	for (GameObject n : children)
	{
		n.Render();
	}
	//render object
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

