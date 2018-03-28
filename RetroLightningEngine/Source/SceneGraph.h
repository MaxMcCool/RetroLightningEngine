#pragma once
#include <vector>
#include "GameObject.h"
class SceneGraph
{
public:
	sf::RenderWindow* mWindow;
	sf::Transform transform;
	SceneGraph();
	void Update();
	void Draw(sf::RenderWindow* window);
	void Attach(GameObject g);
	void RemoveLast();
	std::vector<GameObject> children;
	

};