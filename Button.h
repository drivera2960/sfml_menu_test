/*
 * Button.h
 *  Created on: Apr 20, 2018
 *      Author: Dave
 */

#ifndef BUTTON_H_
#define BUTTON_H_


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

class Button
{
	private:
		sf::RectangleShape button;
		sf::Text nameText;
		//Produce &object;

	public:
		Button(sf::Vector2f dimensions, sf::Vector2f location, sf::Font &font, std::string initText, int thickness, int characterSize, sf::Color colorText, sf::Color colorBoxOutline);
		void changePosition(float x, float y);
		std::string getButtonNameStr();
		sf::RectangleShape getButton();
		sf::Text getButtonName();
		bool clicked(sf::Vector2f mousePosF);

};

Button::Button(sf::Vector2f dimensions, sf::Vector2f location, sf::Font &font, std::string initText, int boxThickness, int characterSize, sf::Color colorText, sf::Color colorBoxOutline)
{
	button.setSize(dimensions);
	button.setPosition(location);
	button.setOutlineThickness(boxThickness);
	button.setOutlineColor(colorBoxOutline);

	nameText.setPosition(location.x + 8, location.y + 8);
	nameText.setFont(font);
	nameText.setString(initText);
	nameText.setCharacterSize(characterSize);
	nameText.setColor(colorText);
}

void Button::changePosition(float x, float y)
{
	button.setPosition(x, y);
}

std::string Button::getButtonNameStr()
{
	return this -> nameText.getString().toAnsiString();
}

sf::RectangleShape Button::getButton()
{
	return this -> button;
}

sf::Text Button::getButtonName()
{
	return this -> nameText;
}

bool Button::clicked(sf::Vector2f mousePosF)
{
	if(button.getGlobalBounds().contains(mousePosF))
	{
		return true;
	}else{
		return false;
	}
}



#endif /* BUTTON_H_ */
