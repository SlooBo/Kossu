#include "Game.h"

static void update(sf::RenderWindow& window, GameHandler& gamehandler);

Game::Game(void)
{
	sf::VideoMode videomode(1240,800);
	sf::RenderWindow window(videomode, "K0SSU");
	window.setFramerateLimit(60);

	GameHandler gamehandler(window);
	Update(window, gamehandler);
}

Game::~Game(void)
{
}

void Game::Update(sf::RenderWindow& window, GameHandler& gamehandler)
{
	sf::Event event;
	sf::Clock clock;

	while(window.isOpen())
	{
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		gamehandler.Update(clock.getElapsedTime());
		clock.restart();
		gamehandler.Draw();
	}	
}