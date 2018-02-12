#pragma once
#include <vector>
class GameObject{
public:
	GameObject(int x, int y);
	GameObject(int x, int y, float rotx, float roty);
	void Update();
	void Render();
	void Attach(GameObject g);
	void RemoveLast();
	std::vector<GameObject> children;
	GameObject* parent;
private:
	int XPosition;
	int YPosition;
	float XRotation;
	float YRotation;
	

};