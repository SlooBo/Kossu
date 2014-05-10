#pragma once
#include "gameobject.h"
class Level :
	public GameObject
{
public:
	Level(void);
	~Level(void);

	void setTexture(sf::Texture& background_text);
	void Draw(sf::RenderWindow& window);

private:
};

