#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class Render
{
public:
	Render(void);
	~Render(void);
	
	sf::Texture ship_text;
	sf::Texture bullet_text;
	sf::Texture background_text;

};

