/*
 * Store.h
 *  Created on: Apr 20, 2018
 *      Author: User
 */

#ifndef STORE_H_
#define STORE_H_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#include "Button.h"

#include "Produce.h"

class Store{
	private:
		std::vector<Produce> produceItems;

		std::vector<double> cartPrice;
		std::vector<sf::Text> cartItems;
		//sf::Text total;

	public:
		Store();
		void listFruit();
		void listMeats();
		void listVegetables();
		void listInfo();

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//Produce Function Declarations
		void addProduce(std::string name, std::string type, double pricePerLlb, sf::Vector2f dimensions,  sf::Font &font, std::string initText);
		void produceGrid();
		int amountOfProduceItems();
		void addProduce(std::string name, std::string type, double pricePerLlb, Button button );
		int checkProduceButtonPressed(sf::Vector2f mousePosF);
		Produce getProduceItem(int pos);
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//Cashier Function Declaration
		void addToCart(double cost, std::string itemName, sf::Font &font);
		double calculateCost();
		sf::Text getCartItem(int pos);
		void organizeCartContents();
		int getCartSize();
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


};

Store::Store(){
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Produce Functions
void Store::addProduce(std::string name, std::string type, double pricePerLlb, sf::Vector2f dimensions, sf::Font &font, std::string initText)
{
	produceItems.push_back(Produce( name,  type,  pricePerLlb,  dimensions, font, initText));
}

void Store::produceGrid()
{
	float x = 350.0f;
	float y = 150.0f;
	int cnt = 0;
	for(int i = 0, max = produceItems.size(); i!=max; ++i )
	{
		produceItems.at(i).changeButtonPosition(x, y);
		produceItems.at(i).changeTextPosition(x+5, y+5);
		x+=200.0f;
		cnt++;

		if(cnt == 4)
		{
			cnt = 0;
			x = 350.0f;
			y += 100.0f;
		}
	}
}

int Store::checkProduceButtonPressed(sf::Vector2f mousePosF)
{
	for(int i = 0, max = produceItems.size(); i!=max;++i)
	{
		if(produceItems.at(i).clicked(mousePosF))
			return i;
	}
		return 444;
}

int Store::amountOfProduceItems()
{
	return produceItems.size();
}

Produce Store::getProduceItem(int pos)
{
	return produceItems.at(pos);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Store::listFruit(){
	for(int i = 0, max = produceItems.size(); i != max; ++i){
		if(produceItems.at(i).getType().compare("fruit") == 0)
			std::cout<<produceItems.at(i).getName()<<std::endl;
	}
}


void Store::listVegetables(){
	for(int i = 0, max = produceItems.size(); i != max; ++i){
		if(produceItems.at(i).getType().compare("vegetable") == 0)
			std::cout<<produceItems.at(i).getName();
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Cashier Functions
double Store::calculateCost()
{
	double totalPrice = 0;

	for(int i = 0, max = cartPrice.size(); i!=max;++i)
	{
		totalPrice += cartPrice.at(i);
	}
	return totalPrice;
}

void Store::addToCart(double cost, std::string itemName, sf::Font &font)
{
	sf::Text item;
	item.setString(itemName);
	item.setFont(font);
	item.setCharacterSize(25);
	item.setColor(sf::Color::Black);

	cartPrice.push_back(cost);

	cartItems.push_back(item);
}

void Store::organizeCartContents()
{
		float x = 600.0f;
		float y = 200.0f;
		int cnt = 0;
		for(int i = 0, max = cartItems.size(); i!=max; ++i )
		{
			cartItems.at(i).setPosition(x, y);
			y+=35.0f;
		}
}

sf::Text Store::getCartItem(int pos)
{
	return cartItems.at(pos);
}

int Store::getCartSize()
{
	return cartItems.size();
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif /* STORE_H_ */
