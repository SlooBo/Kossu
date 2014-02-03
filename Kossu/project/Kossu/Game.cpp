#include "Game.h"


Game::Game(void)
{
}


Game::~Game(void)
{
}

int Game::PlayGame()
{
	//Textures
	sf::Texture pirate_text;
	if(!pirate_text.loadFromFile("pirate.png"))
	{
		std::cout << "Couldn't load file: pirate.png" << std::endl;
	}
	
	//Player
	sf::Sprite player_sprite;
	player_sprite.setOrigin(32,32);
	player_sprite.setTexture(pirate_text);
	sf::FloatRect player_boundingBox = player_sprite.getGlobalBounds();

	//locations
	player_sprite.setPosition(400,400);
	
	sf::RenderWindow window_game(sf::VideoMode(800,800),"GAME");

	//shit
	const float maxY = 0.2f;
	const float minY = -0.2f;
	const sf::Vector2f gravity(0.0f,0.1f);
	sf::Vector2f velocity(0,0.1f);
	
	sf::Clock deltaclock;

	while(window_game.isOpen())
	{
		//deltatime
		sf::Time deltatime = deltaclock.restart();
			
		//GAMELOOP
		player_sprite.move(velocity);


		if(velocity.y < maxY)
		{
			velocity += gravity * deltatime.asSeconds() * 0.2f;
		}
		
		//INPUT
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			if(velocity.y > minY)
			{
				velocity.y -= .9f * deltatime.asSeconds() * 0.2f;		
				
				velocity.x = -sin(player_sprite.getRotation() * deltatime.asSeconds());
			}
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			player_sprite.rotate(-.5f);
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
				
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			player_sprite.rotate(.5f);
		}


		sf::Event event;
		while(window_game.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window_game.close();
			}
		}
		window_game.clear();

		window_game.draw(player_sprite);

		window_game.display();
	}
	return 1;
}