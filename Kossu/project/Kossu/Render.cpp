#include "Render.h"


Render::Render(void)
{
	//PLAYER
	if(!ship_text.loadFromFile("assets/ship_small.png"))
	{
		std::cout << "Couldn't load file: ship_small.png" << std::endl;
	}

	//BULLET
	if(!bullet_text.loadFromFile("assets/bullet.png"))
	{
		std::cout << "Couldn't load file: bullet.png" << std::endl;
	}

	//BACKGROUND
	if(!background_text.loadFromFile("assets/map1.png"))
	{
		std::cout << "Couldn't load file: map1.png" << std::endl;
	}
}

Render::~Render(void)
{
}
