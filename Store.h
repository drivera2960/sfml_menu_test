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
//#include "Produce.h"
#include "ProduceItemButton.h"
//#include "ProduceItemButton.h"

class Store{
	private:
//		std::vector<Produce> produceItems;
		std::vector<ProduceItemButton> produceButtons;

	public:
		Store();
		void listFruit();
		void listMeats();
		void listVegetables();
		void listInfo();
//		void addProduce(std::string name, std::string type, double pricePerLlb);

		void addProduce(std::string name, std::string type, double pricePerLlb, sf::Vector2f dimensions,  sf::Font &font, std::string initText );
		void produceGrid();
		sf::RectangleShape printProduceItem(int pos);
		sf::Text printProduceItemText(int pos);
		int amountOfProduceButtons();

		void addProduce(std::string name, std::string type, double pricePerLlb, Button button );

		ProduceItemButton getProduceItem(int pos);

};

Store::Store(){
}

void Store::addProduce(std::string name, std::string type, double pricePerLlb, sf::Vector2f dimensions,  sf::Font &font, std::string initText)
{
	//produceItems.push_back(Produce(name, type, pricePerLlb));
	produceButtons.push_back(ProduceItemButton( name,  type,  pricePerLlb,  dimensions, font,  initText));

}
/*
void Store::addProduce(std::string name, std::string type, double pricePerLlb, Button button )
{
	produceItems.push_back(Produce(name, type, pricePerLlb, button));
}
*/

void Store::produceGrid()
{
	float x = 400.0f;
	float y = 150.0f;
	int cnt = 0;
	for(int i = 0, max = produceButtons.size(); i!=max; ++i )
	{
		produceButtons.at(i).changeButtonPosition(x, y);
		produceButtons.at(i).changeTextPosition(x+5, y+5);
		x+=120.0f;
		cnt++;

		if(i == 6)
		{
			cnt = 0;
			x = 400.0f;
			y += 50.0f;
		}

	}

}

/*
sf::RectangleShape Store::printProduceItem(int pos)
{
		return produceButtons.at(pos).getButton();
}

sf::Text Store::printProduceItemText(int pos)
{
		return produceButtons.at(pos).getButtonName();
}
*/
int Store::amountOfProduceButtons()
{
	return produceButtons.size();
}

ProduceItemButton Store::getProduceItem(int pos)
{
	return produceButtons.at(pos);
}




void Store::listFruit(){
	for(int i = 0, max = produceButtons.size(); i != max; ++i){
		if(produceButtons.at(i).getType().compare("fruit") == 0)
			std::cout<<produceButtons.at(i).getName()<<std::endl;
	}
}

/*
void Store::listVegetables(){
	for(int i = 0, max = produceItems.size(); i != max; ++i){
		if(produceItems.at(i).getType().compare("vegetable") == 0)
			std::cout<<produceItems.at(i).getName();
	}
}
*/


#endif /* STORE_H_ */
