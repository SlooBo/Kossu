#pragma once

#define PI (3.141592653589793)

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "GameHandler.h"

class Game
{
public:
	Game(void);
	~Game(void);

	void Update(sf::RenderWindow& window, GameHandler& gamehandler);
};