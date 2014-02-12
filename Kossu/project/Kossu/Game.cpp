#include "Game.h"


Game::Game(void)
{
}


Game::~Game(void)
{
}


void Game::rotate(float angle)
{
	x = -cos((90 + angle) * PI / 180) * 0.1f;
	y = -sin((90 + angle) * PI / 180) * 0.1f;

}


int Game::PlayGame()
{
	////////////////////////////Textures//////////////////////////////

	//PLAYER
	sf::Texture pirate_text;
	if(!pirate_text.loadFromFile("pirate.png"))
	{
		std::cout << "Couldn't load file: pirate.png" << std::endl;
	}

	//BULLET
	sf::Texture bullet_text;
	if(!bullet_text.loadFromFile("bullet.png"))
	{
		std::cout << "Couldn't load file: bullet.png" << std::endl;
	}

	//BACKGROUND

	sf::Texture background_text;
	if(!background_text.loadFromFile("map1.png"))
	{
		std::cout << "Couldn't load file: map1.png" << std::endl;
	}
	
	////////////////////////////Sprites//////////////////////////////

	//Player
	sf::Sprite player_sprite;
	player_sprite.setOrigin(32,32);
	player_sprite.setTexture(pirate_text);
	sf::FloatRect player_boundingBox = player_sprite.getGlobalBounds();

	//Bullet
	sf::Sprite bullet_sprite;
	bullet_sprite.setOrigin(8,8);
	bullet_sprite.setTexture(bullet_text);
	sf::FloatRect bullet_boundingBox = bullet_sprite.getGlobalBounds();

	//Background
	sf::Sprite background_sprite;
	background_sprite.setTexture(background_text);


	////////////////////////////locations//////////////////////////////

	player_sprite.setPosition(400,400);
	
	////////////////////////////Window//////////////////////////////

	sf::RenderWindow window_game(sf::VideoMode(800,800),"GAME");
	sf::View view1(sf::FloatRect(0,0,800,800));
	

	////////////////////////////shit//////////////////////////////


	const float maxY = 0.2f;
	const float minY = -0.2f;
	const sf::Vector2f gravity(0.0f,0.3f);
	sf::Vector2f velocity(0,0);
	
	sf::Clock deltaclock;

	while(window_game.isOpen())
	{
		//deltatime
		sf::Time deltatime = deltaclock.restart();
			
		//
		player_sprite.move(velocity);
		view1.move(velocity);


		//Gravity
		if(velocity.y < maxY)
		{
			velocity += gravity * deltatime.asSeconds() * 0.2f;
		}

		//INPUT
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


		sf::Event event;
		while(window_game.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window_game.close();
			}
		}
		window_game.setView(view1);

		window_game.clear();
		
		window_game.draw(background_sprite);
		window_game.draw(player_sprite);

		window_game.display();
	}
	return 1;
}