#include "Input.h"

Input::Input(void)
{
}

Input::~Input(void)
{
}

bool Input::keyboard_A()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::A);
}

bool Input::keyboard_D()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::D);	
}

bool Input::keyboard_W()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::W);	
}

bool Input::keyboard_Space()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
}