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
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <array>

#include "Store.h"
#include "TextBox.h"
#include "Button.h"
#include "Produce.h"
sf::RenderWindow window(sf::VideoMode(1200, 800), "Mr. Djald's Supermarket", sf::Style::Close^sf::Style::Titlebar);
sf::Font font;
sf::Text total;
std::vector<std::string> names = {"Dave" , "Dean", "Jon"};

sf::Texture produceImageTexture;
sf::Sprite produceImageSprite;

std::string line;
int selectedProduce;
int windowDepth = 0;



int main()
{
	if (!font.loadFromFile("arial.ttf"))
			return EXIT_FAILURE;

	if(!produceImageTexture.loadFromFile("Images/fresh-produce.jpg"))
		return 0;
	produceImageSprite.setTexture(produceImageTexture);
	produceImageSprite.setPosition(0.0f, 0.0f);

	std::cout<< std::fixed << std::setprecision(2);	//Sets cout to output numbers with 2 decimal places

	Store supermarket = Store();		//Creates object <supermarket>

	std::ifstream productDataFile;		//Initializes productDataFile as a istream object
	productDataFile.open("FOOD.txt");	//Data will be streamed from the <FOOD.txt> file

	// Saves one line of the text file into "line", until eof (end of file) is reached.
	while(std::getline(productDataFile, line))
	{

		std::vector<std::string> lineVec;			//<lineVec> is a vector that will be used to store the split strings
													//from the string "line"
		std::istringstream iss(line);				//create a string stream "iss" to operate on the string line.

	//While-loop will split "line" by the spaces it contains.  It will store the splitted strings into "lineVec"
		while( iss >> line )
		{
			replace( line.begin(), line.end(), '_', ' ' );	//remove underscores from strings
		    lineVec.push_back(line);
		}
	//The following bool expressions check what sections the each entry belongs to.
		if (lineVec.at(0).compare("produce") == 0)
		{
			supermarket.addProduce(lineVec.at(1), lineVec.at(2), stod(lineVec.at(3)), sf::Vector2f(100,30), font, lineVec.at(1));
		}

		lineVec.clear();
	}
		productDataFile.close();	//Closes the stream of productDataFile when the eof has been reached.

	////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////

		supermarket.listFruit();

	////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////

	TextBox nameBox = TextBox(sf::Vector2f(400,50), sf::Vector2f(window.getSize().x/2 - 400/2, 400.0f) ,5, font, "Enter Full Name");
	TextBox box = TextBox(sf::Vector2f(400,50), sf::Vector2f(window.getSize().x/2 - 400/2, 6.0f) ,5, font, "Search");

	Button produceButton = Button(sf::Vector2f(200,57), sf::Vector2f(5.0f, 5.0f) , font, "Produce", 5, 25, sf::Color::Black, sf::Color::Magenta );
	Button meatsButton = Button(sf::Vector2f(200,57), sf::Vector2f(5.0f, 72.0f) , font, "Meats", 5, 25, sf::Color::Black, sf::Color::Blue);
	Button grainsButton = Button(sf::Vector2f(200,57), sf::Vector2f(5.0f, 139.0f) , font, "Grains", 5, 25, sf::Color::Black, sf::Color::Black);
	Button dairyButton = Button(sf::Vector2f(200,57), sf::Vector2f(5.0f, 206.0f) , font, "Dairy", 5, 25, sf::Color::Black, sf::Color::Black);
	Button drinksButton = Button(sf::Vector2f(200,57), sf::Vector2f(5.0f, 273.0f) , font, "Drinks", 5, 25, sf::Color::Black, sf::Color::Black);
	Button cartButton = Button(sf::Vector2f(100.0f, 45.0f), sf::Vector2f(1095.0f, 20.0f) , font, "Pay", 9, 22, sf::Color::Black, sf::Color::Red);

    while (window.isOpen())
    {

    	sf::Vector2i mousePos = sf::Mouse::getPosition( window );
    	sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );

    	sf::Event event;

    	if(windowDepth == 0)
    	{
    	while(window.pollEvent(event) )
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

    				if ( nameBox.clicked( mousePosF) )	//detect if an object of TextBox was clicked
    				{
    					std::cout << "Clicked nameBox" << std::endl;
    					window.clear(sf::Color::White);
    					window.draw(nameBox.getTextBox());
    					window.draw(nameBox.getBoxText());
    					window.display();
    					while(window.waitEvent(event))
    					{
    						if(event.type == sf::Event::TextEntered)
    						{
    							nameBox.textEntered(event.text.unicode);
    							window.clear(sf::Color::White);
    							window.draw(nameBox.getTextBox());
    							window.draw(nameBox.getBoxText());
    							window.display();
    							if(event.text.unicode == 13)	//Must have a particular action be a break statement (<enter> key)
    							{
    								std::cout<<nameBox.getBoxTextStr()<<std::endl;
    								windowDepth++;
    								std::cout<<windowDepth<<std::endl;
    								break;
    							}
    						}
    					}
    				}
    			}

    		}
    			window.clear(sf::Color::White);
    			window.draw(nameBox.getTextBox());
    			window.draw(nameBox.getBoxText());
    			window.display();
    	}
    	continue;
    	}


//Window depth 1
    	if(windowDepth == 1)
    	{
    	while(window.pollEvent(event) )
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
        			if ( box.clicked( mousePosF) )	//detect if an object of TextBox was clicked
        			{
        				std::cout << "Clicked textBox" << std::endl;
        				window.clear(sf::Color::White);
        				window.draw(box.getTextBox());
        				window.draw(box.getBoxText());
        				window.display();
        				while(window.waitEvent(event))
        				{
        					if(event.type == sf::Event::TextEntered)
        					{
        						box.textEntered(event.text.unicode);
        						window.clear(sf::Color::White);
        						window.draw(box.getTextBox());
        						window.draw(box.getBoxText());
        						window.display();
        						if(event.text.unicode == 13)	//Must have a particular action be a break statement (<enter> key)
        						{
        							std::cout<<box.getBoxTextStr()<<std::endl;
        							for(int i = 0, max = names.size(); i<max; ++i)
									{
        								if(box.getBoxTextStr().compare(names.at(i)) == 0)
        									std::cout<<"found person" << std::endl;
									}
        							break;
        						}
        					}
        				}
        			}
        			if(cartButton.clicked(mousePosF))
        			{
        				windowDepth = 37;
        			break;
        			}
        			if(produceButton.clicked(mousePosF))
        			{
        				std::cout<<"Produce Button Clicked"<<std::endl;
        				while(window.waitEvent(event))
        				{
        					mousePos = sf::Mouse::getPosition( window );
     					    sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );

     					    supermarket.produceGrid(); //creates produce items grid (sets locations for buttons)

     					    //Draw all the buttons
        			        window.clear(sf::Color::White);
        			        window.draw(produceButton.getButton());
        			        window.draw(produceButton.getButtonName());
        			        window.draw(meatsButton.getButton());
        			        window.draw(meatsButton.getButtonName());
        			        window.draw(grainsButton.getButton());
        			        window.draw(grainsButton.getButtonName());
        			        window.draw(dairyButton.getButton());
        			        window.draw(dairyButton.getButtonName());
        			        window.draw(drinksButton.getButton());
        			        window.draw(cartButton.getButton());
        			        window.draw(cartButton.getButtonName());
        			        window.draw(drinksButton.getButtonName());

        			        for(int i = 0, max = supermarket.amountOfProduceItems(); i!=max;++i)
        			        {
        			        	window.draw(supermarket.getProduceItem(i).getButton());
        			        	window.draw(supermarket.getProduceItem(i).getButtonName());
        			        }

        					window.display();
        					if(event.type == sf::Event::KeyPressed)
        					{
        						if(event.key.code == sf::Keyboard::M)
        							break;
        					}
        					if(event.type == sf::Event::MouseButtonPressed)
        					{
        						std::cout<<supermarket.getProduceItem(0).getName()<<std::endl;

        						selectedProduce = supermarket.checkProduceButtonPressed(mousePosF);
        						if(selectedProduce != 444)
        						{
        							windowDepth++;
        							std::cout<<"windowDepth: "<<windowDepth<<std::endl;
        							std::cout<<"yep"<<std::endl;
        						}

        					}
        					if(windowDepth != 1)
        						break;
        				}

        			}
        			break;
				}


        	}

        window.clear(sf::Color::White);
        window.draw(produceButton.getButton());
        window.draw(produceButton.getButtonName());
        window.draw(meatsButton.getButton());
        window.draw(meatsButton.getButtonName());
        window.draw(grainsButton.getButton());
        window.draw(grainsButton.getButtonName());
        window.draw(dairyButton.getButton());
        window.draw(dairyButton.getButtonName());
        window.draw(drinksButton.getButton());
        window.draw(drinksButton.getButtonName());
        window.draw(box.getTextBox());
        window.draw(box.getBoxText());
        window.draw(cartButton.getButton());
        window.draw(cartButton.getButtonName());
        window.display();
        }

    	}

    	//Construct Produce Frame
    	if(windowDepth == 2)
    	{
    		std::string name = "Name: ";
    		std::string aisle = "Aisle: ";
    		std::string pricePerLlb = "Price Per Llb: $";

    		Button produceNameText = Button(sf::Vector2f(0.0f,0.0f), sf::Vector2f(0.0f, 0.0f) , font, (name).append(supermarket.getProduceItem(selectedProduce).getButtonNameStr()), 0, 50, sf::Color::Black, sf::Color::Magenta);
    		Button produceTypeText = Button(sf::Vector2f(0.0f,0.0f), sf::Vector2f(0.0f, 60.0f) , font, aisle.append("Produce"), 0, 35, sf::Color::Black, sf::Color::Magenta);
    		std::string priceUnformatted = pricePerLlb.append(std::to_string(supermarket.getProduceItem(selectedProduce).getPricePerLlb()));
    		Button producePriceText = Button(sf::Vector2f(0.0f,0.0f), sf::Vector2f(0.0f, 100.0f) , font, priceUnformatted, 0, 35, sf::Color::Black, sf::Color::Magenta);

    		Button addToCart = Button(sf::Vector2f(150.0f, 50.0f), sf::Vector2f(600.0f, 100.0f) , font, "Add to Cart", 3, 25, sf::Color::Black, sf::Color::Black);
    		Button backButton = Button(sf::Vector2f(100.0f, 45.0f), sf::Vector2f(1095.0f, 20.0f) , font, "Go Back", 9, 22, sf::Color::Black, sf::Color::Red);

    		while(window.pollEvent(event) )
    		{
    			std::cout<< "Mouse Pos X: "<<mousePosF.x <<std::endl;
    			std::cout<< "Mouse Pos Y: " <<mousePosF.y <<std::endl;
    			switch(event.type)
    			{
    				case(sf::Event::Closed):
    				{
    					window.close();
    					break;
    				}
    				case(sf::Event::MouseButtonPressed):
					{
    					if(addToCart.clicked(mousePosF))
    					{
    						supermarket.addToCart(supermarket.getProduceItem(selectedProduce).getPricePerLlb() , supermarket.getProduceItem(selectedProduce).getButtonNameStr(), font);
    					}

    					if(backButton.clicked(mousePosF))
    					{
    						windowDepth--;
    					}
    					break;
					}


    				case(sf::Event::KeyPressed):		//Go back to menu
    				{
    					if(event.key.code == sf::Keyboard::M)
    					windowDepth--;
    					break;
    				}
    				default:
    					break;
    			}

    			window.clear(sf::Color::White);

    			window.draw(produceNameText.getButtonName());
    			window.draw(produceTypeText.getButtonName());
    			window.draw(producePriceText.getButtonName());
    			window.draw(addToCart.getButton());
    			window.draw(addToCart.getButtonName());
    			window.draw(backButton.getButton());
    			window.draw(backButton.getButtonName());
    			//window.draw(supermarket.getProduceItem(selectedProduce).getButtonName());
    			//window.draw(produceImageSprite);
    			window.display();
    		}
    	}



    	if(windowDepth == 37)
    	{
    		supermarket.organizeCartContents();
    		std::string finito = "Total Cost: $";

    		total.setString(  finito.append(std::to_string(supermarket.calculateCost())) );
    		total.setFont(font);
    		total.setCharacterSize(30);
    		total.setColor(sf::Color::Red);
    		total.setPosition( window.getSize().x/2,700.0f);

    		while(window.pollEvent(event) )
    		{
    			switch(event.type)
    			{
    				case(sf::Event::Closed):
					{
    					window.close();
    					break;
					}



    			}
    			window.clear(sf::Color::Yellow);

    			for(int i = 0, max = supermarket.getCartSize(); i!=max; ++i)
    			{
    				window.draw(supermarket.getCartItem(i));
    			}

    			window.draw(total);
    			window.display();
    		}



    	}


    }
    return 0;
}
