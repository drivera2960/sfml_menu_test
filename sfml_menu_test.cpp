/*
 * sfml_graphics_tutorial.cpp
 *
 *  Created on: Apr 5, 2018
 *      Author: Dave
 */
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

//#include "Dropdown.h"
/*
int main()
{
//VideoMode defines the inner size of the window in pixels and its name.  Third argument affects the
//style of the window
	sf::RenderWindow window(sf::VideoMode(1500, 800), "Mr. Djald's Supermarket", sf::Style::Close^sf::Style::Titlebar);

	sf::Texture produce_button;
	sf::Sprite produceButton;
	sf::RectangleShape searchBar(sf::Vector2f(300,50));

	sf::Text searchBarText;
	sf::String text;


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

	searchBarText.setFont(font);
	searchBarText.setPosition(sf::Vector2f(650 , 5));
	searchBarText.setString("Search Bar");
	searchBarText.setCharacterSize(25);
	searchBarText.setColor(sf::Color::Red);

	std::cout<< window.getSize().x <<std::endl;


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
						sf::Event textEvent;

						while (window.pollEvent(textEvent))
						{
							if (event.type == sf::Event::TextEntered)
							{
								//if(textEvent)
								//if(textEvent.text.unicode<123 && event.text.unicode > 97)
							//	{
									text += textEvent.text.unicode;
									searchBarText.setString(text);
								//}
							//}
							window.draw(searchBarText);
							}
						window.display();
						}
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



			}


		//window.clear();
		window.clear(sf::Color::White);
		window.draw(produceButton);
		window.draw(searchBar);
		window.draw(searchBarText);
		window.display();
		}
	}

	return 0;
}
*/

std::vector<std::string> names = {"Dave" , "Dean", "Jon"};

int main(){
	sf::RenderWindow window(sf::VideoMode(1500, 800), "Mr. Djald's Supermarket", sf::Style::Close^sf::Style::Titlebar);
            sf::Font font;
            if (!font.loadFromFile("arial.ttf"))
            return EXIT_FAILURE;

            sf::String searchInput;
            sf::Text searchText;
        	std::string searchTextStr;
            sf::RectangleShape searchBar(sf::Vector2f(300,50));

        	searchBar.setPosition((window.getSize().x/2) - searchBar.getSize().x/2, 2.0f);
        	searchBar.setOutlineThickness(2);
        	searchBar.setOutlineColor(sf::Color::Black);

            searchText.setPosition(sf::Vector2f(600 , 5));
            searchText.setFont(font);
            searchText.setString("Search Bar");
            searchText.setCharacterSize(25);
            searchText.setColor(sf::Color::Red);



    while (window.isOpen())
        {
        sf::Event event;
             while(window.pollEvent(event))
             {

            	 if (event.type == sf::Event::Closed)
            		 window.close();


            	 if(event.type == sf::Event::MouseButtonPressed)
            	 {
            		 sf::Vector2i mousePos = sf::Mouse::getPosition( window );
            		 sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );
        			 std::cout<<"pressed"<<std::endl;

            		 if(searchBar.getGlobalBounds().contains(mousePosF))
            		 {

            			 //sf::Event textEvent;
            			 searchInput.clear();
            			 searchText.setString(searchInput);
            			 //window.draw(searchText);
            			 //window.display();
            			 while(window.waitEvent(event))
            			{
                			 if(event.type == sf::Event::TextEntered)
                			 {

            				// while(event.text.unicode != 49)
            				 //{
            				 	 if(event.text.unicode<123 && event.text.unicode > 32 )
            				 	 {
            				 		 searchInput += event.text.unicode;
            				 		 searchText.setString(searchInput);

            				 		 searchTextStr = searchText.getString().toAnsiString();

            				 		 window.draw(searchText);
            				         window.display();
            				 	 }
            				 //}

            				 	 if(event.text.unicode == 13)
            				 	 {
            				 		 if(searchTextStr.compare(names.at(1)) == 0)
            				 		        {
            				 		        	std::cout<<"found person" << std::endl;

            				 		        }else
            				 		        	std::cout<<"person not found" << std::endl;
            				 		 break;
            				 	 }
                			 }
            			 }


            		 }
            	 }
        window.clear(sf::Color::White);
        window.draw(searchBar);
        window.draw(searchText);
        window.display();

      }

}
    return 0;

}
