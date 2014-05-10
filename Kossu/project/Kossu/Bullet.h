#pragma once

#include "gameobject.h"

#include <list>

class Bullet :	public GameObject
{
public:
	Bullet(sf::Vector2f position, int angle);
	Bullet();
	~Bullet(void);

	void getVel(sf::Vector2f pos, int rangle);
	void Update(const sf::Time& elapsedTime);
	void setTexture(sf::Texture& bullet_text);
	void Draw(sf::RenderWindow& window);
	
	std::vector<Bullet> bullets;

private:

};