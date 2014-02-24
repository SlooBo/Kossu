#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#include "Mainmenu.h"
#include "Game.h"

enum states
{
	MENU_STATE = 1,
	EXIT_STATE = 2,
	GAME_STATE = 3,
	OPTIONS_STATE = 4
};

int main()
{	
	Mainmenu menucall;
	Game gameCall;
	
	int state = GAME_STATE;

	while(true)
	{
		std::cout << state << std::endl;

		if(state == MENU_STATE)
		{
		std::cout << "Opening Main Menu" << std::endl;
		menucall.DrawMenu(state);
		}

		if(state == EXIT_STATE)
		{
			std::cout << "Exit" << state << std::endl;
			break;
		}

		if(state == GAME_STATE)
		{
			std::cout << "Game starting" << std::endl;
			Game::Game();
		}
		if(state == OPTIONS_STATE)
		{
		
		}
	}
	system("pause");
	return EXIT_SUCCESS;
}