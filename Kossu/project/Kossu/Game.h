#pragma once

#include "input.h"

#define PI (3.141592653589793)

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <math.h>

class Game
{
public:
	Game(void);
	~Game(void);
	
	void rotate(float angle);
	int PlayGame();
	float x, y, a;
};