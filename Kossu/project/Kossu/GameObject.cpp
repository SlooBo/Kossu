#include "GameObject.h"


GameObject::GameObject(void)
{
}


GameObject::~GameObject(void)
{
}

const sf::Vector2f& GameObject::Direction() const
{
	return direction;
}

const sf::Vector2f& GameObject::Position() const
{
	return position;
}

void GameObject::setDirection(const sf::Vector2f value)
{
	direction = value;
}

void GameObject::setPosition(const sf::Vector2f value)
{
	position = value;
}

void GameObject::setRotation(const int value)
{
	rotation = value;
}

void GameObject::Update(const sf::Time& elapsedTime)
{
	elapsedTime;
}

void GameObject::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void GameObject::SetTexture(sf::Texture& value)
{
	sprite.setTexture(value);
}
