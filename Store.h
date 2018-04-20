/*
 * Store.h
 *
 *  Created on: Apr 20, 2018
 *      Author: User
 */

#ifndef STORE_H_
#define STORE_H_

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>


#include "Produce.h"
class Store{
	private:

		std::vector<Produce> produceItems;
	public:
		Store();
		void listFruit();
		void listMeats();
		void listVegetables();
		void listInfo();


		void addProduce(std::string name, std::string type, double pricePerLlb);

};

Store::Store(){
}

void Store::addProduce(std::string name, std::string type, double pricePerLlb)
{
	produceItems.push_back(Produce(name, type, pricePerLlb));
}

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



#endif /* STORE_H_ */
