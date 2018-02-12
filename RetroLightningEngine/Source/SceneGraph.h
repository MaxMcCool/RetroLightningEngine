#pragma once
#include <vector>
#include "GameObject.h"
class SceneGraph
{
public:
	SceneGraph();
	void Update();
	void Render();
	void Attach(GameObject g);
	void RemoveLast();
protected:
	std::vector<GameObject> children;

};