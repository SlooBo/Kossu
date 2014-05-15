#include "Input.h"

Input::Input(void)
{
}

Input::~Input(void)
{
}

//PLAYER 1
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

//PLAYER 2
bool Input::keyboard_UP()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
}

bool Input::keyboard_RIGHT()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Right);	
}

bool Input::keyboard_LEFT()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Left);	
}

bool Input::keyboard_RCTR()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::RControl);
}