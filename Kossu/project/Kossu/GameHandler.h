#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Input.h"
#include "Player.h"
#include "Render.h"
#include "Bullet.h"
#include "Level.h"

class GameHandler : public GameObject
{
public:
	GameHandler(sf::RenderWindow& window);
	~GameHandler(void);

	void Update(const sf::Time& elapsedTime);
	void Draw();
	void Render();
	
	std::vector<Bullet>bullets;

private:	
	void Input();
	void initPlayer();
	void updatePlayer(const sf::Time& elapsedTime);
	void updateBullets(const sf::Time& elapsedTime);

	sf::RenderWindow& window;
	sf::Texture texture;
	sf::FloatRect bounds;
	sf::Texture bullet_text;
	sf::Texture background_text;
	sf::Texture bar_text;
	sf::Clock bulletTimer;
	Player player;
	Level level;
};

