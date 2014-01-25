#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Game.h"

class input : public Game
{
public:
	input(void);
	~input(void);

	void Move();
};

