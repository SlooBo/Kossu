#include "GameHandler.h"
#include "Global.h"

const sf::Vector2f startPosition(100,100);
const sf::Vector2f startPosition2(105,105);

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
	player2.Draw(window);

	window.display();
}

void GameHandler::Input()
{
	//PLAYER 1
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
		if(bulletTimer.getElapsedTime().asSeconds() > bulletCD)
		{
 			bulletTimer.restart();	
			sf::Vector2f bulletPosition = player.Position();

			sf::Vector2f bulletDirection;

			bulletDirection.x = -cos((90 + player.rangle) * PI / 180); 
			bulletDirection.y = -sin((90 + player.rangle) * PI / 180);

			bulletPosition += bulletDirection * 35.f;

			bullets.push_back(Bullet(bulletPosition,player.rangle));
		}
	}

	//PLAYER 2
	if(Input::keyboard_LEFT())
	{
		player2.rotateLeft();
	}

	if(Input::keyboard_RIGHT())
	{
		player2.rotateRight();
	}

	if(Input::keyboard_UP())
	{
		player2.forward();
	}

	if(Input::keyboard_RCTR())
	{
		if(bulletTimer.getElapsedTime().asSeconds() > bulletCD)
		{
			bulletTimer.restart();			
			bullets2.push_back(Bullet(player2.Position(),player2.rangle));
		}
	}
}

void GameHandler::initPlayer()
{
	player.setTexture(texture);
	player2.setTexture(texture);

	//level muualle
	level.setTexture(background_text);

	player.setPosition(startPosition);
	player2.setPosition(startPosition2);
}

void GameHandler::updatePlayer(const sf::Time& elapsedTime)
{
	sf::View view1(sf::FloatRect(0,0,800,600));

	player.Update(elapsedTime);
	player.Camera(view1);
	window.setView(view1);

	player2.Update(elapsedTime);
}

float vectorLenght(sf::Vector2f vec)   //TODO: VERY BAD HACK OF LEAVING THIS HERE.
{
	return sqrt( vec.x * vec.x + vec.y * vec.y );
}

void GameHandler::updateBullets(const sf::Time& elapsedTime)
{
	for(unsigned i = 0; i < bullets.size(); i++)
	{
		bullets[i].SetTexture(bullet_text);
		bullets[i].Update(elapsedTime);

		if( vectorLenght(bullets[i].Position() - player2.Position()) < 50)
		{
			printf(" OSSUUUUU KAKKOSEEN");
		}

		if(bullets[i].Position().x > 2048 || bullets[i].Position().y > 2048
			|| bullets[i].Position().x < 0 || bullets[i].Position().y < 0)
		{
			bullets.erase(bullets.begin());
		}

	}

	for(unsigned i = 0; i < bullets2.size(); i++)
	{
		bullets2[i].SetTexture(bullet_text);
		bullets2[i].Update(elapsedTime);

		if( vectorLenght(bullets2[i].Position() - player.Position()) < 50)
		{
			printf(" OSSUUUUU YKKÖSEEE");
		}

		if(bullets2[i].Position().x > 2048 || bullets2[i].Position().y > 2048
			|| bullets2[i].Position().x < 0 || bullets2[i].Position().y < 0)
		{
			bullets2.erase(bullets2.begin());
		}
	}
}

void GameHandler::Render()
{
	Render::Render();
}