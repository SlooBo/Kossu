#include "Mainmenu.h"


Mainmenu::Mainmenu(void)
{
}


Mainmenu::~Mainmenu(void)
{
}

int Mainmenu::DrawMenu(int state)
{
	//Tekstuurit	
	sf::Texture pirate_text;

	if(!pirate_text.loadFromFile("pirate.png"))
	{
			std::cout << "Couldn't load file: pirate.png" << std::endl;
	}

	sf::Texture backGround_text;

	if(!backGround_text.loadFromFile("background.png"))
	{
		std::cout << "Couldn't load file: background.png" << std::endl;
	}	
	
	//background
	sf::Sprite backGround_sprite;
	backGround_sprite.setTexture(backGround_text);


	//Startgame item
	sf::Sprite menuItem_sprite;
	menuItem_sprite.setOrigin(32,32);
	menuItem_sprite.setTexture(pirate_text);
	sf::FloatRect menuItem_boundingBox = menuItem_sprite.getGlobalBounds();

	//Exitgame item
	sf::Sprite menuItem2_sprite;
	menuItem2_sprite.setOrigin(32,32);
	menuItem2_sprite.setTexture(pirate_text);
	sf::FloatRect menuItem2_boundingBox = menuItem2_sprite.getGlobalBounds();

	//Locations
	menuItem_sprite.setPosition(400,200);
	menuItem2_sprite.setPosition(400,400);

	//MAIN WINDOW
	std::cout << "Drawing Menu window" << std::endl;
	sf::RenderWindow window_menu(sf::VideoMode(800,600),"MAIN MENU");
	

	while(window_menu.isOpen())
	{
		sf::Event event;
		while(window_menu.pollEvent(event))
		{				
			sf::Vector2i localPosition = sf::Mouse::getPosition(window_menu);

			std::cout << localPosition.x << " + " << localPosition.y  << std::endl;
			
			if(event.type == sf::Event::MouseButtonReleased 
				&& localPosition.x < menuItem_sprite.getPosition().x + menuItem_boundingBox.width
				&& localPosition.x > menuItem_sprite.getPosition().x - menuItem_boundingBox.width
				&& localPosition.y < menuItem_sprite.getPosition().y + menuItem_boundingBox.height
				&& localPosition.y > menuItem_sprite.getPosition().y - menuItem_boundingBox.height)
			{
				std::cout << "Start game" << std::endl;			
				state = 3;						
				window_menu.close();
			}

			if(event.type == sf::Event::MouseButtonReleased 
				&& localPosition.x < menuItem2_sprite.getPosition().x + menuItem2_boundingBox.width
				&& localPosition.x > menuItem2_sprite.getPosition().x - menuItem2_boundingBox.width
				&& localPosition.y < menuItem2_sprite.getPosition().y + menuItem2_boundingBox.height
				&& localPosition.y > menuItem2_sprite.getPosition().y - menuItem2_boundingBox.height)
			{
				std::cout << "Exit Game" << std::endl;	
				state = 2;
				
				std::cout << state << std::endl;
				return state;
				std::cout << state << std::endl;
				window_menu.close();
			}
			
			if(event.type == sf::Event::Closed)
			{
				std::cout << "Closing Window" << std::endl;
				window_menu.close();
			}
		}

		window_menu.clear();

		window_menu.draw(backGround_sprite);
		window_menu.draw(menuItem_sprite);
		window_menu.draw(menuItem2_sprite);

		window_menu.display();
	}
	return state;
}