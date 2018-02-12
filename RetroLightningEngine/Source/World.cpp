#include "World.h"
#include "SFML\Graphics.hpp"
#include "SceneGraph.h"
#include "GameObject.h"


World::World()
{

}
World::World(sf::RenderWindow* awindow)
{
	mRenderWindow = awindow;
	BuildWorld();
}

void World::Update()
{
	mSceneGraph.Update();
	Render();
}

void World::Render()
{
	mSceneGraph.Render();
}

void World::BuildWorld()
{
	GameObject obj1 = GameObject(0,0);
	GameObject obj2 = GameObject(0,0,0.0f,0.0f);

	mSceneGraph.Attach(obj1);
	obj1.Attach(obj2);


}
void World::display()
{
	//draw SceneGraph here

	mRenderWindow->display();
}

bool World::IsOpen()
{
	return mRenderWindow->isOpen();
}
