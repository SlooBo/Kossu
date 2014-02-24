#pragma once

#include "gameobject.h"

#include <list>

class Bullet :	public GameObject
{
public:
	Bullet(void);
	~Bullet(void);

	void getVel(sf::Vector2f pos, sf::Vector2f vel);
	void Update(const sf::Time& elapsedTime);

private:
	std::list<Bullet> bullets;
};