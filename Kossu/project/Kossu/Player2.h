#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "GameObject.h"
#include "Bullet.h"

#include <iostream>

class Player2 : public GameObject
{
public:
	Player2(void);
	~Player2(void);

	void Draw(sf::RenderWindow& window);
	void Update(const sf::Time& elapsedTime);
	//void shoot();
	//void bulletShoot();
	void setTexture(sf::Texture& texture);
	void rotateLeft();
	void rotateRight();
	void forward();
	void takeDamage(int value);
	void Camera(sf::View& view1);	
	bool isAlive;
		
	float rangle;
	float x, y;	

private:
	sf::Vector2f velocity;
	//sf::Clock bulletTimer;
	int health;

	void updatePosition(const sf::Time& elapsedTime);
};

