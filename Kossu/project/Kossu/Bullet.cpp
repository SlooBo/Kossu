#include "Bullet.h"

static const sf::IntRect texture_rect(0,0,16,16);
static const sf::Vector2f texture_origin(texture_rect.width * 0.5f, texture_rect.height * 0.5f);

static const int bullet_speed = 1000;

Bullet::Bullet(sf::Vector2f position, int angle)
{
	getVel(position, angle);
}

Bullet::Bullet(){}

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

void Bullet::getVel(sf::Vector2f pos, int rangle)
{	
	position.x = pos.x;
	position.y = pos.y;
	
	direction.x = -cos((90 + rangle) * PI / 180); 
	direction.y = -sin((90 + rangle) * PI / 180);

	sprite.setRotation(rangle);

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
	//GameObject::Draw(window);

}