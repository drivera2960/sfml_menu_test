/*
 * sfml_graphics_tutorial.cpp
 *
 *  Created on: Apr 5, 2018
 *      Author: User
 */
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
//VideoMode defines the inner size of the window in pixels and its name.  Third argument affects the
//style of the window
	sf::RenderWindow window(sf::VideoMode(1500, 800), "Mr. Djald's Supermarket", sf::Style::Close^sf::Style::Titlebar);

	sf::Texture produce_button;
	sf::Sprite produceButton;
	sf::RectangleShape searchBar(sf::Vector2f(300,50));
	sf::Text title;

	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
		std::cout<<"font is a nogo\n\n";


	if (!produce_button.loadFromFile("produce_button.png"))
			    std::cout<<"nogo on button\n\n";//error message

	produceButton.setTexture(produce_button);
	produceButton.setPosition( 0.0f, 0.0f );

	//retrieve in event statement//
	//float produceButtonWidth = produceButton.getLocalBounds().width;
	//float produceButtonHeight = produceButton.getLocalBounds().height;

	searchBar.setPosition(750 - produceButton.getLocalBounds().width, 2.0f);
	//searchBar.setSize(sf::Vector2f(300,50));
	searchBar.setOutlineThickness(2);
	searchBar.setOutlineColor(sf::Color::Black);

	title.setFont(font);
	title.setPosition(sf::Vector2f(650 , 5));
	title.setString("Search Bar");
	title.setCharacterSize(25);
	title.setColor(sf::Color::Red);

	while(window.isOpen())	//This while-loop will run the program as long as the window is open.
	{
		sf::Event event;	// check all the window's events that were triggered since the last iteration of the loop

//Within a window, we must poll for events happening within it.
//Whenever we get an event, we check its type, and react accordingly.
		while (window.pollEvent(event))
		{
			switch(event.type)
			{
				//Closes the window
				case(sf::Event::Closed):
				{
					window.close();
					break;
				}
				case(sf::Event::MouseButtonPressed):
				{
					sf::Vector2i mousePos = sf::Mouse::getPosition( window );
					sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );
					if ( produceButton.getGlobalBounds().contains( mousePosF ) )
					{
						std::cout << "Clicked sprite button" << std::endl;
					}

					if(searchBar.getGlobalBounds().contains(mousePosF))
					{
						std::cout << "clicked rectangle button" <<std::endl;
					}
					break;
				}
				case(sf::Event::KeyPressed):
				{
					if(event.key.code == sf::Keyboard::M)
						produceButton.move(0.0f, 100.0f);
					if(event.key.code == sf::Keyboard::N)
						produceButton.move(0.0f, -100.0f);
					break;
				}


			/*
			//Closes the window
			if(event.type == sf::Event::Closed)
				window.close();

			if(event.type == sf::Event::MouseButtonPressed)
			{
				sf::Vector2i mousePos = sf::Mouse::getPosition( window );
				sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );
				if ( produceButton.getGlobalBounds().contains( mousePosF ) )
				{
					std::cout << "Clicked!" << std::endl;
				}
			}

			if(event.type == sf::Event::KeyPressed)
			{

				if(event.key.code == sf::Keyboard::M)
					produceButton.move(0.0f, 100.0f);
				if(event.key.code == sf::Keyboard::N)
					produceButton.move(0.0f, -100.0f);
			}


			 */
			}


		//window.clear();
		window.clear(sf::Color::White);
		window.draw(produceButton);
		window.draw(searchBar);
		window.draw(title);
		window.display();
		}
	}

	return 0;
}
