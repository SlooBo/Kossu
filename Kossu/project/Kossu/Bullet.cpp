#include "Bullet.h"

static const sf::IntRect texture_rect(0,0,16,16);
static const sf::Vector2f texture_origin(texture_rect.width * 0.5f, texture_rect.height * 0.5f);

static const int bullet_speed = 100;

Bullet::Bullet(void)
{
}


Bullet::~Bullet(void)
{
	
}

void Bullet::setTexture(sf::Texture& bullet_text)
{
	GameObject::SetTexture(bullet_text);
	
	sprite.setTextureRect(texture_rect);
	sprite.setOrigin(texture_origin);
	sprite.setScale(0.5f,0.5f);
}

void Bullet::getVel(sf::Vector2f pos, sf::Vector2f vel)
{	
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
}

void Bullet::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	GameObject::Draw(window);
}