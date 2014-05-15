#include "Player2.h"

static const float speed = 5.0f;
static const int maxHp = 100;
static const int minY = -100;
static const int maxY = 100;
static const int minX = -100;
static const int maxX = 100;
static const int bulletCD = 0.2f;
static const sf::Vector2f gravity(0,30);
static const sf::IntRect texture_rect(0,0,256,256);
static const sf::Vector2f texture_origin(texture_rect.width * 0.5f, texture_rect.height * 0.5f);


Player2::Player2(void)
{
	rangle = 0;
	x = 0;
	y = 0;
}


Player2::~Player2(void)
{
}

void Player2::rotateLeft()
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

void Player2::rotateRight()
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

void Player2::forward()
{	
	x = -cos((90 + rangle) * PI / 180); 
	y = -sin((90 + rangle) * PI / 180);

	velocity.x += x;
	velocity.y += y;
}

void Player2::takeDamage(int value)
{
	health -= value;

	if(health == 0)
	{
		isAlive = false;
		std::cout << "ded" << std::endl;
	}
}

void Player2::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);

	//GameObject::Draw(window);
}

void Player2::Update(const sf::Time& elapsedTime)
{
	updatePosition(elapsedTime);
}

void Player2::updatePosition(const sf::Time& elapsedTime)
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
		position.x = 0;
	}	
	
	if(position.x > 2048)
	{
		position.x = 2048;
	}

	if(position.y < 0)
	{
		position.y = 0;
	}	
	
	if(position.y > 2048)
	{
		position.y = 2048;
	}

	//MOVEMENT
	position += velocity * elapsedTime.asSeconds() * speed;
	
	sprite.setRotation(rangle);
	sprite.setPosition(position);
}

void Player2::Camera(sf::View& view1)
{
	view1.move(position.x - 400,position.y - 300);
}


void Player2::setTexture(sf::Texture& texture)
{	

	GameObject::SetTexture(texture);
	
	sprite.setTextureRect(texture_rect);
	sprite.setOrigin(texture_origin);
	sprite.setScale(0.3f,0.3f);
}
