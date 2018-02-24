#pragma once
#include <vector>
#include "BaseComponent.h"
<<<<<<< HEAD
#include "Transform.h"
=======
#include "TransformComponent.h"
>>>>>>> Transform
class GameObject{
public:
	GameObject(float x, float y);
	GameObject(float x, float y, float rotx, float roty);
	void Update();
	void Render();
	DirectX::XMMATRIX GetTransform();
	void Attach(GameObject g);
	void RemoveLast();
	TransformComponent transform;
	std::vector<GameObject> children;
	std::vector<BaseComponent> componentList;
	GameObject* parent;
	BaseComponent* components;
	Transform* transforms;
	
private:
	int XPosition;
	int YPosition;
	float XRotation;
	float YRotation;
};