#pragma once

#include <SFML\System.hpp>
#include <SFML\Window.hpp>

#include "GameObject.h"

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

	static bool keyboard_RCTR();
	static bool keyboard_UP();
	static bool keyboard_LEFT();
	static bool keyboard_RIGHT();

private:
	Input(void);
	~Input(void);
};

