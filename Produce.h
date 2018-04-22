/*
 * Produce.h
 *
 *  Created on: Apr 20, 2018
 *      Author: User
 */

#ifndef Produce_H_
#define Produce_H_


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

class Produce
{
	friend class Store;
	private:
		sf::RectangleShape button;
		sf::Text nameText;

		const std::string name;
		const std::string type;
		double pricePerLlb;
		double supermarketQuantity;

		sf::Text typeText;
		sf::Text pricePerLlbText;

	public:
		Produce(std::string name, std::string type, double pricePerLlb, sf::Vector2f dimensions,  sf::Font &font, std::string initText);
		void changeButtonPosition(float x, float y);
		void changeTextPosition(float x, float y);
		std::string getButtonNameStr();
		std::string getButtonTypeStr();
		sf::RectangleShape getButton();
		sf::Text getButtonName();				//or getNameText()
		sf::Text getPPPText();						//get pricePerLlb value in sf::Text form
		sf::Text getTypeText();

		bool clicked(sf::Vector2f mousePosF);


		std::string getType();
		std::string getName();
		double getPricePerLlb();
};


Produce::Produce(std::string name, std::string type, double pricePerLlb, sf::Vector2f dimensions,  sf::Font &font, std::string initText):name(name), type(type)
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

	this -> typeText.setString(type);

	this -> pricePerLlbText.setString( std::to_string(pricePerLlb) );
}

void Produce::changeButtonPosition(float x, float y)
{
	button.setPosition(x, y);
}

std::string Produce::getButtonNameStr()
{
	return this -> nameText.getString().toAnsiString();
}

sf::RectangleShape Produce::getButton()
{
	return this -> button;
}

sf::Text Produce::getButtonName()
{
	return this -> nameText;
}

bool Produce::clicked(sf::Vector2f mousePosF)
{
	if(button.getGlobalBounds().contains(mousePosF))
	{
		return true;
	}else{
		return false;
	}
}

void Produce::changeTextPosition(float x, float y)
{
	nameText.setPosition(x, y);
}

std::string Produce::getType()
{
	return this -> type;
}

double Produce::getPricePerLlb()
{
	return this -> pricePerLlb;
}

std::string Produce::getName()
{
	return this -> name;
}


sf::Text Produce::getPPPText()						//get pricePerLlb value in sf::Text form
{
	return this ->pricePerLlbText;
}
sf::Text Produce::getTypeText()
{
	return this -> typeText;
}

std::string Produce::getButtonTypeStr()
{
	return this -> type;
}


#endif /* Produce_H_ */
