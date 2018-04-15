#include "World.h"
#include "SFML\Graphics.hpp"
#include "SceneGraph.h"
#include "GameObject.h"
#include <algorithm>
#include <iostream>
#include <cmath>
World::World()
{

}


World::World(sf::RenderWindow* awindow)
{
	boxtex.loadFromFile("Assets/attack.png");
	mRenderWindow = awindow;
	mSceneGraph = SceneGraph();
	BuildWorld();
}

void World::Update()
{
	//do a different check using height, width , top ,left
	
	display();
}

void World::BuildWorld()
{
	bulletStart = sf::Vector2<float>(800, 700);
	bullet.loadFromFile("Assets/clash2.png");
	bg.loadFromFile("Assets/background.jpg");
	background.setTexture(bg);
	for (int i = 0; i < 10; i++)
	{
		pbIsFiring[i] = false;
		pbullet[i].setPosition(bulletStart);
		pbullet[i].setScale(0.1, 0.1);
	}




	player = GameObject(0.0f,0.0f);
	GameObject obj1 = GameObject(50.0f, 50.0f);
	box = GameObject(500.0, 0.0f);
	GameObject bullet = GameObject(500.0, 300.0,0.0,1.0);
	player.Attach(obj1);
	mSceneGraph.Attach(player);
	mSceneGraph.Attach(box);
	mSceneGraph.Attach(bullet);

}
void World::display()
{
	mRenderWindow->clear();
	background.setPosition(0, 0);
	background.setTexture(bg);
	mRenderWindow->draw(background);
	for (int i = 0; i < 10; i++)
	{
		pbullet[i].setTexture(bullet);
		if (pbIsFiring[i]) {
			pbullet[i].setPosition(pbullet[i].getPosition().x, pbullet[i].getPosition().y + bulletspeed);
			if (pbullet[i].getPosition().y <= 0)
			{
				pbullet[i].setPosition(bulletStart);
				pbIsFiring[i] = false;
			}
		}
		mRenderWindow->draw(pbullet[i]);
	}




	float bulletspeed = mSceneGraph.children[2].getYSpeed();
	mSceneGraph.children[2].setSpeed(1.0, 0.0);
	

	for (GameObject n : mSceneGraph.children) {
		if (n.children.size() > 0) {
			sf::Vector2f curPos = n.sprite.getPosition();
			n.sprite.setPosition(curPos.x + n.xSpeed, curPos.y + n.ySpeed);
			n.sprite.setTexture(n.texture);

			for (GameObject m : n.children)
			{
				sf::Vector2f curchilPos = m.sprite.getPosition();
				m.sprite.setPosition(curchilPos.x + m.xSpeed + n.xSpeed,curchilPos.y+m.ySpeed+n.ySpeed);
				m.sprite.setTexture(m.texture);
				
			}
		}
		else
		{
			sf::Vector2f curPos = n.sprite.getPosition();
			n.sprite.setPosition(curPos.x + n.xSpeed, curPos.y + n.ySpeed);
			n.sprite.setTexture(n.texture);
			
		}
	}
	if (player.sprite.getPosition().y < 500)
	{
	player.sprite.setPosition(player.sprite.getPosition().x, player.sprite.getPosition().y + gravity);
	box.sprite.setPosition(box.sprite.getPosition().x, box.sprite.getPosition().y + gravity);
	}
	player.sprite.setPosition(player.sprite.getPosition().x+playeraccelx,player.sprite.getPosition().y+playeraccely);
	player.sprite.setTexture(player.texture);
	box.sprite.setPosition(box.sprite.getPosition().x + boxaccelx, box.sprite.getPosition().y + boxaccely);
	box.sprite.setTexture(boxtex);
	mRenderWindow->draw(player.sprite);
	player.children[0].sprite.setPosition(player.sprite.getPosition().x + player.children[0].XPosition + childaccelx, player.sprite.getPosition().y + player.children[0].YPosition + childaccely);
	if (player.children[0].sprite.getPosition().y + player.children[0].YPosition >= 500)
	{
		player.children[0].YPosition = player.children[0].sprite.getPosition().y + player.children[0].YPosition - 500;
	}
	player.children[0].sprite.setTexture(player.children[0].texture);
	mRenderWindow->draw(player.children[0].sprite);
	mRenderWindow->draw(box.sprite);
	sf::FloatRect one;
	sf::FloatRect two;
	one = player.GetWorldTransform().transformRect((sf::FloatRect)player.sprite.getTextureRect());
	two = box.GetWorldTransform().transformRect((sf::FloatRect)box.sprite.getTextureRect());
	
	bool coldim1;
	bool coldim2;
	coldim1 = player.sprite.getPosition().x + one.width >= box.sprite.getPosition().x && box.sprite.getPosition().x >= player.sprite.getPosition().x;
	coldim2 = player.sprite.getPosition().y + one.height >= box.sprite.getPosition().y && box.sprite.getPosition().y >= player.sprite.getPosition().y;
	
	if (coldim1 && coldim2)
	{
		sf::Vector2f diff = player.sprite.getPosition() - box.sprite.getPosition();
		boxaccelx = playeraccelx;
		boxaccely = playeraccely;
		playeraccelx = -playeraccelx;
		playeraccely = -playeraccely;
		
	}
	int sign = playeraccelx / std::abs(playeraccelx);
	if ((std::abs(playeraccelx) - 0.03f) > 0) {
		playeraccelx = sign * (std::abs(playeraccelx) - 0.03f);
	}
	else
	{
		playeraccelx = 0;
	}
	
	//draw SceneGraph here
	//mSceneGraph.Draw(mRenderWindow);
	
	mRenderWindow->display();
	//mRenderWindow->display();
}

bool World::IsOpen()
{
	return mRenderWindow->isOpen();
}

void World::handleEvent(sf::Event e)
{
	if (e.type == sf::Event::KeyPressed) {
		switch (e.key.code)
		{
		case sf::Keyboard::Key::A:
			playeraccelx = -2;
			break;
		case sf::Keyboard::Key::D:
			playeraccelx = 2;
			break;
		case sf::Keyboard::Key::W:
			playeraccely = -2;
			break;
		case sf::Keyboard::Key::S:
			playeraccely = +2;
			break;
		case sf::Keyboard::Left:

			break;
		case sf::Keyboard::Right:
			break;
		case sf::Keyboard::Up:
			break;
		case sf::Keyboard::Down:
			break;
		case sf::Keyboard::Space:
			pbIsFiring[bulletcounter] = true;
			pbullet[bulletcounter].setPosition(player.getSprite()->getPosition());
			pbullet[bulletcounter].move(player.getSprite()->getTextureRect().width / 2, 0);
			bulletcounter++;
			if (bulletcounter >= 10)
			{
				bulletcounter = 0;
			}
			break;
		}
		
	}
	/*if (e.type == sf::Event::KeyReleased)
	{
		switch (e.key.code)
		{
		case sf::Keyboard::Key::A:
			playeraccelx = 0;
			break;
		case sf::Keyboard::Key::D:
			playeraccelx = 0;
			break;
		case sf::Keyboard::Key::W:
			playeraccely = 0;
			break;
		case sf::Keyboard::Key::S:
			playeraccely = 0;
			break;
		case sf::Keyboard::Left:

			break;
		case sf::Keyboard::Right:
			break;
		case sf::Keyboard::Up:
			break;
		case sf::Keyboard::Down:
			break;
		}
	}*/
}

