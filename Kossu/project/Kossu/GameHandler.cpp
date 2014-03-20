#include "GameHandler.h"


GameHandler::GameHandler(sf::RenderWindow& window)	: bounds(window.getViewport(window.getView())), window(window)
{
	initPlayer();
	Render();
	texture.loadFromFile("assets/ship_small.png");
	bullet_text.loadFromFile("assets/bullet.png");
}


GameHandler::~GameHandler(void)
{
}


void GameHandler::Update(const sf::Time& elapsedTime)
{
	Input();
	updatePlayer(elapsedTime);
	updateBullets(elapsedTime);
}

void GameHandler::Draw()
{
	window.clear();
	
	player.Draw(window);
	player.bullet.Draw(window);
	
	window.display();
}

void GameHandler::Input()
{
	if(Input::keyboard_A())
	{
		player.rotateLeft();
	}

	if(Input::keyboard_D())
	{
		player.rotateRight();
	}

	if(Input::keyboard_W())
	{
		player.forward();
	}

	if(Input::keyboard_Space())
	{
		player.shoot();
	}
}

void GameHandler::initPlayer()
{
	player.setTexture(texture);

	player.bullet.setTexture(bullet_text);

	const sf::Vector2f startPosition(100,100);

	player.setPosition(startPosition);

}

void GameHandler::updatePlayer(const sf::Time& elapsedTime)
{
	player.Update(elapsedTime);
}

void GameHandler::updateBullets(const sf::Time& elapsedTime)
{
	player.bullet.Update(elapsedTime);
}

void GameHandler::Render()
{
	Render::Render();
}