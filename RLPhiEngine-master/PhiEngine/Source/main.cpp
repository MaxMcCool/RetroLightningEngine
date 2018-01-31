#include "EngineInitialization.h"
#include <SFML/Graphics.hpp>

using namespace std;

void main(int argc, char **argv)
{
	LPCTSTR Title = "PhiEngine";
	if (!IsOnlyInstance(Title))
	{
		//error
	}
	DWORDLONG SpaceNeeded = 300000000;
	if (!CheckStorage(SpaceNeeded))
	{
		//error
	}
	DWORDLONG RAMNeeded = 300000000;
	DWORDLONG VRAMNeeded = 300000000;
	if (!CheckMemory(RAMNeeded, VRAMNeeded))
	{
		//error
	}

	DWORD Success = ReadCPUSpeed();
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	system("pause");
}