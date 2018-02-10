#include "SceneGraph.h"
#include "GameObject.h"
SceneGraph::SceneGraph()
{

}

void SceneGraph::Update()
{
	for (GameObject n : children)
	{
		n.Update();
	}
}

void SceneGraph::Render()
{

}

void SceneGraph::Attach(GameObject g)
{
	children.push_back(g);
}

void SceneGraph::RemoveLast()
{
	children.pop_back();
}
