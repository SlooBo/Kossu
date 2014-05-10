#include "GameHandler.h"

const sf::Vector2f startPosition(100,100);
const float bulletCD = 0.2f;

GameHandler::GameHandler(sf::RenderWindow& window)	: bounds(window.getViewport(window.getView())), window(window)
{
	initPlayer();
	Render();
	texture.loadFromFile("assets/ship_small.png");
	bullet_text.loadFromFile("assets/bullet.png");
	background_text.loadFromFile("assets/map1.png");
	bar_text.loadFromFile("assets/bar.png");
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
	
	level.Draw(window);

	for(unsigned i = 0; i < bullets.size(); i++)
	{
		bullets[i].Draw(window);
	}	

	player.Draw(window);	

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
		//player.shoot();	

		if(bulletTimer.getElapsedTime().asSeconds() > bulletCD)
		{
			bulletTimer.restart();			
			bullets.push_back(Bullet(player.Position(),player.rangle));
		}
	}
}

void GameHandler::initPlayer()
{
	player.setTexture(texture);

	//level muualle
	level.setTexture(background_text);

	player.setPosition(startPosition);
}

void GameHandler::updatePlayer(const sf::Time& elapsedTime)
{
	sf::View view1(sf::FloatRect(0,0,800,600));

	player.Update(elapsedTime);
	player.Camera(view1);
	window.setView(view1);
}

void GameHandler::updateBullets(const sf::Time& elapsedTime)
{
	for(unsigned i = 0; i < bullets.size(); i++)
	{
		bullets[i].SetTexture(bullet_text);
		bullets[i].Update(elapsedTime);

		if(bullets[i].Position().x > 2048 || bullets[i].Position().y > 2048
			|| bullets[i].Position().x < 0 || bullets[i].Position().y < 0)
		{
			bullets.erase(bullets.begin());
		}
	}
}

void GameHandler::Render()
{
	Render::Render();
}