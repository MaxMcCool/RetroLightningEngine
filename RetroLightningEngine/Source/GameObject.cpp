#include "GameObject.h"
#include "BaseComponent.h"
#include "TransformComponent.h"
GameObject::GameObject(float x, float y)
{
	XPosition = x;
	YPosition = y;
	XRotation = 0;
	YRotation = 0;
	DirectX::XMMATRIX xm = DirectX::XMMATRIX(x, 0, 0, 0, 0, y, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
	
	transform = TransformComponent();
	
	transform.Translate(xm);
	componentList.push_back((BaseComponent)transform);
}

GameObject::GameObject(float x, float y, float rotx, float roty)
{
	XPosition = x;
	YPosition = y;
	XRotation = rotx;
	YRotation = roty;
	DirectX::XMMATRIX xm = DirectX::XMMATRIX(x, 0, 0, 0, 0, y, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
	DirectX::XMMATRIX xmr = DirectX::XMMatrixRotationX(rotx) * DirectX::XMMatrixRotationY(roty);
	transform = TransformComponent();
	transform.Translate(xm);
	transform.Rotate(xmr);
	componentList.push_back((BaseComponent)transform);
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

DirectX::XMMATRIX GameObject::GetTransform()
{
	return transform.model * parent->GetTransform();
}