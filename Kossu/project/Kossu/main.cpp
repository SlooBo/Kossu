#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#include "Mainmenu.h"
#include "Game.h"

int main()
{	
	Mainmenu menucall;
	Game gameCall;
	
	int state = 1;
	int *statepoint;
	statepoint = &state;

	while(1)
	{
		std::cout << "Opening Main Menu" << std::endl;
		menucall.DrawMenu(state);
		
		if(state == 2)
		{
			std::cout << "perkele" << state << std::endl;
		}

		if(state == 3)
		{
			std::cout << "asd"<< state << std::endl;
			gameCall.PlayGame();
		}
	}
	system("pause");
	return EXIT_SUCCESS;
}