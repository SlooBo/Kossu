#include "Player.h"
#include "Global.h"

Player::Player(void)
{
	rangle = 0;
	x = 0;
	y = 0;
	health = 100;
}


Player::~Player(void)
{
}

void Player::rotateLeft()
{
	rangle -= 2;

	if (rangle < 0)
	{
		rangle = 360;
	}

	if( rangle > 360)
	{
		rangle = 0;
	}
}

void Player::rotateRight()
{
	rangle += 2;

	if (rangle <= 0)
	{
		rangle = 360;
	}

	if( rangle >= 360)
	{
		rangle = 0;
	}
}

void Player::forward()
{	
	x = -cos((90 + rangle) * PI / 180); 
	y = -sin((90 + rangle) * PI / 180);

	velocity.x += x;
	velocity.y += y;
}

void Player::takeDamage(int value)
{
	health -= value;

	if(health == 0)
	{
		isAlive = false;
		std::cout << "ded" << std::endl;
	}
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);

	//GameObject::Draw(window);
}

void Player::Update(const sf::Time& elapsedTime)
{
	updatePosition(elapsedTime);
}

void Player::updatePosition(const sf::Time& elapsedTime)
{	
	//VELOCITY CONTROL
	if(velocity.y < maxY)
	{		
		velocity += gravity * elapsedTime.asSeconds();	
	}

	if(velocity.y < minY)
	{
		velocity.y = minY;
	}	

	//MOVEMENT BOUNDS
	if(position.x < 0)
	{
		velocity.x = -velocity.x;
	}	
	
	if(position.x > 2048)
	{
		velocity.x = -velocity.x;
	}

	if(position.y < 0)
	{
		velocity.y = -velocity.y;
	}	
	
	if(position.y > 2048)
	{
		velocity.y = -velocity.y;
	}

	//MOVEMENT
	position += velocity * elapsedTime.asSeconds() * speed;
	
	sprite.setRotation(rangle);
	sprite.setPosition(position);
}

void Player::Camera(sf::View& view1)
{
	view1.move(position.x - 400,position.y - 300);
}


void Player::setTexture(sf::Texture& texture)
{	
	GameObject::SetTexture(texture);
	
	sprite.setTextureRect(texture_rect);
	sprite.setOrigin(texture_origin);
	sprite.setScale(0.3f,0.3f);
}
