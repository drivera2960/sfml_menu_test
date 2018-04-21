/*
 * ProduceItemButton.h
 *
 *  Created on: Apr 20, 2018
 *      Author: User
 */

#ifndef PRODUCEITEMBUTTON_H_
#define PRODUCEITEMBUTTON_H_


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

//#include "Produce.h"
class ProduceItemButton
{
	friend class Store;
	private:
		sf::RectangleShape button;
		sf::Text nameText;

		const std::string name;
		const std::string type;
		double pricePerLlb;
		double supermarketQuantity;

	public:
		ProduceItemButton(std::string name, std::string type, double pricePerLlb, sf::Vector2f dimensions,  sf::Font &font, std::string initText);
		void changeButtonPosition(float x, float y);
		void changeTextPosition(float x, float y);
		std::string getButtonNameStr();
		sf::RectangleShape getButton();
		sf::Text getButtonName();
		bool clicked(sf::Vector2f mousePosF);

		std::string getType();
		std::string getName();
		double getPricePerLlb();
};

ProduceItemButton::ProduceItemButton(std::string name, std::string type, double pricePerLlb, sf::Vector2f dimensions,  sf::Font &font, std::string initText):name(name), type(type)
{
	button.setSize(dimensions);
	button.setOutlineThickness(5);
	button.setOutlineColor(sf::Color::Black);

	nameText.setFont(font);
	nameText.setString(initText);
	nameText.setCharacterSize(15);
	nameText.setColor(sf::Color::Black);

	this -> pricePerLlb = pricePerLlb;
	this -> supermarketQuantity = 100;
}

void ProduceItemButton::changeButtonPosition(float x, float y)
{
	button.setPosition(x, y);
}

std::string ProduceItemButton::getButtonNameStr()
{
	return this -> nameText.getString().toAnsiString();
}

sf::RectangleShape ProduceItemButton::getButton()
{
	return this -> button;
}

sf::Text ProduceItemButton::getButtonName()
{
	return this -> nameText;
}

bool ProduceItemButton::clicked(sf::Vector2f mousePosF)
{
	if(button.getGlobalBounds().contains(mousePosF))
	{
		return true;
	}else{
		return false;
	}
}

void ProduceItemButton::changeTextPosition(float x, float y)
{
	nameText.setPosition(x, y);
}

std::string ProduceItemButton::getType()
{
	return this -> type;
}

double ProduceItemButton::getPricePerLlb()
{
	return this -> pricePerLlb;
}

std::string ProduceItemButton::getName()
{
	return this -> name;
}

#endif /* PRODUCEITEMBUTTON_H_ */
