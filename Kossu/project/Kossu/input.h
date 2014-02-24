#pragma once

#include <SFML\System.hpp>
#include <SFML\Window.hpp>

#include "GameObject.h"
#include "Player.h"

#include <iostream>

#define PI (3.141592653589793)

class Input
{
public:
	static sf::Vector2f direction();
	static float rotation();
	static bool keyboard_Space();
	static bool keyboard_W();
	static bool keyboard_A();
	static bool keyboard_D();

private:
	Input(void);
	~Input(void);
};

