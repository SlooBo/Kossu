#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <math.h>


#define PI (3.141592653589793)

class GameObject
{
public:
	GameObject(void);
	~GameObject(void);

	void Draw(sf::RenderWindow& window);

	const sf::Vector2f& Direction() const;
	const sf::Vector2f& Position() const;

	void Update(const sf::Time& elapsedTime);

	void SetTexture(sf::Texture& value);
	void setDirection(const sf::Vector2f value);
	void setPosition(const sf::Vector2f value);
	void setRotation(const int value);



protected:
	sf::Sprite sprite;
	sf::Vector2f position;
	sf::Vector2f direction;
	int rotation;
};

