#include "Level.h"

static const sf::IntRect texture_rect(0,0,2048,2048);
static const sf::Vector2f texture_origin(texture_rect.width * 0.5f, texture_rect.height * 0.5f);


Level::Level(void)
{
}


Level::~Level(void)
{
}

void Level::setTexture(sf::Texture& background_text)
{
	GameObject::SetTexture(background_text);		
	sprite.setTextureRect(texture_rect);
}

void Level::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	GameObject::Draw(window);
}