#include "SceneGraph.h"
#include "GameObject.h"
#include <iostream>
SceneGraph::SceneGraph()
{
	transform = sf::Transform::Identity;
}

void SceneGraph::Update()
{
}

void SceneGraph::Draw(sf::RenderWindow* window)
{
	
	for (GameObject n : children)
	{
		n.Draw(window);
	}
}

void SceneGraph::Attach(GameObject g)
{
	children.push_back(g);
}

void SceneGraph::RemoveLast()
{
	children.pop_back();
}
