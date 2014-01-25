#include "input.h"


input::input(void)
{
}


input::~input(void)
{
}

void input::Move()
{	
if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if(velocity.y > minY)
		{
			float angle;
			angle = player_sprite.getRotation();				
			Game::rotate(angle);

			velocity.x += x * 0.001f;
			velocity.y += y * 0.001f;
		}
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		player_sprite.rotate(-0.1f);
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{				
	
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		player_sprite.rotate(0.1f);
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
			
	}
}
