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

std::vector<std::string> names = {"Dave" , "Dean", "Jon"};

int main()
{
	sf::RenderWindow window(sf::VideoMode(1500, 800), "Mr. Djald's Supermarket", sf::Style::Close^sf::Style::Titlebar);
            sf::Font font;
            if (!font.loadFromFile("arial.ttf"))
            return EXIT_FAILURE;


            sf::Texture produce_button;
            sf::Sprite produceButton;
            if (!produce_button.loadFromFile("produce_button.png"))
            	std::cout<<"nogo on button\n\n";//error message

            produceButton.setTexture(produce_button);
            produceButton.setPosition( 0.0f, 0.0f );

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
        	switch(event.type)
        	{
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
        			std::cout<<"Pressed search bar"<<std::endl;
        			searchInput.clear();
        			searchText.setString(searchInput);
        			window.clear(sf::Color::White);
        			window.draw(searchBar);
        			window.draw(searchText);
        			window.display();

        			while(window.waitEvent(event))
        			{
        				if(event.type == sf::Event::TextEntered)
        				{
        					if(event.text.unicode<123 && event.text.unicode > 31)	//Take in characters
        					{
        						searchInput += event.text.unicode;
        						searchText.setString(searchInput);

        						searchTextStr = searchText.getString().toAnsiString();
        						window.clear(sf::Color::White);
        						window.draw(searchBar);
        						window.draw(searchText);
        						window.display();
        					}
        					if(event.text.unicode == 8)		//Backspace
        					{
        						if(searchTextStr.size() > 0)
        						{
        							searchTextStr = searchText.getString().toAnsiString();
        							searchTextStr.pop_back();
        							searchText.setString(searchTextStr);
        							searchInput.erase(searchInput.getSize()-1, 1);

        							window.clear(sf::Color::White);
        							window.draw(searchBar);
        							window.draw(searchText);
        							window.display();
        						}
        					}
        					//Here search for specific items
        					if(event.text.unicode == 13) //Enter key pressed
        					{
        						searchTextStr = searchText.getString().toAnsiString();
        						std::cout<<searchTextStr<<std::endl;
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

        window.clear(sf::Color::White);
        window.draw(produceButton);
        window.draw(searchBar);
        window.draw(searchText);
        window.display();
        }
    }
    return 0;
}
