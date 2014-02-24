#include "Bullet.h"

static const int bullet_speed = 100;

Bullet::Bullet(void)
{
}


Bullet::~Bullet(void)
{
	
}

void Bullet::getVel(sf::Vector2f pos, sf::Vector2f vel)
{	
	//sprite.setTexture;

	position.x = pos.x;
	position.y = pos.y;
	direction.x = vel.x;
	direction.y = vel.y;
	
	sf::Time elapsedTime;
	Update(elapsedTime);
}

void Bullet::Update(const sf::Time& elapsedTime)
{
	position.x += direction.x * bullet_speed * elapsedTime.asSeconds();
	position.y += direction.y * bullet_speed * elapsedTime.asSeconds();

	sprite.setPosition(position);
	
	std::cout << position.x << " " << position.y << std::endl;
}