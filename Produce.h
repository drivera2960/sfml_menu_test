/*
 * Produce.h
 *
 *  Created on: Apr 20, 2018
 *      Author: User
 */

#ifndef PRODUCE_H_
#define PRODUCE_H_

#include <string>
#include <vector>
#include <iomanip>


#include "Store.h"

class Produce{
	friend class Store;
		private:
			const std::string name;
			const std::string type;
			double pricePerLlb;
			double supermarketQuantity;

		public:
			Produce(std::string name, std::string type, double pricePerLlb);
			std::string getType();
			Produce addProduce(std::string name, std::string section);
			std::string getName();
			double getPricePerLlb();

};
Produce::Produce(std::string name, std::string type, double pricePerLlb):name(name), type(type){
	this -> pricePerLlb = pricePerLlb;
	this -> supermarketQuantity = 100;
}

std::string Produce::getName(){
	return this -> name;
}

std::string Produce::getType(){
	return this-> type;
}

double Produce::getPricePerLlb(){
	return this -> pricePerLlb;
}



#endif /* PRODUCE_H_ */
