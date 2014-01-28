#include "Game.h"


Game::Game(void)
{
}


Game::~Game(void)
{
}

int Game::PlayGame()
{
	std::cout << "Game starting" << std::endl;
	
	sf::RenderWindow window_game(sf::VideoMode( 1000,1000),"GAME");
	return 0;
}