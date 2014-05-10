#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "GameObject.h"
#include "Bullet.h"

#include <iostream>

class Player : public GameObject
{
public:
	Player(void);
	~Player(void);

	void Draw(sf::RenderWindow& window);
	void Update(const sf::Time& elapsedTime);
	void shoot();
	void bulletShoot();
	void setTexture(sf::Texture& texture);
	void rotateLeft();
	void rotateRight();
	void forward();
	void takeDamage(int value);
	void Camera(sf::View& view1);	
	bool isAlive;

	Bullet bullet;

private:
	sf::Vector2f velocity;
	sf::Clock bulletTimer;
	int health;
	float rangle;
	float x, y;	

	void updatePosition(const sf::Time& elapsedTime);
};

