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
sf::Font erasFont;
sf::Text total;
std::vector<std::string> names = {"Dave" , "Dean", "Jon"};

sf::Texture produceImageTexture;
sf::Sprite produceImageSprite;

std::string line;

int selectedProduce;
int windowDepth = 0;

std::string priceUnformatted;
int characterPos;
std:: string priceFormatted;

sf::Texture initial;
sf::Texture second;
sf::Texture produceTexture;
sf::Texture meatsTexture;
sf::Texture drinksTexture;
sf::Texture pharmacyTexture;
sf::Texture grainsTexture;
sf::Texture cosmeticsTexture;
sf::Texture dairyTexture;
sf::Texture bakeryTexture;
sf::Texture snacksTexture;
sf::Texture deliTexture;
sf::Texture hygieneTexture;

std::string appendStr(std::string str1, std::string str2);

int main()
{


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

///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
		if (!font.loadFromFile("arial.ttf"))
					return EXIT_FAILURE;

		if (!erasFont.loadFromFile("ErasITC-DEMI.ttf"))
			return EXIT_FAILURE;

	    if(!initial.loadFromFile("Images/Entrance.jpg"))
	    {
	        std::cout<<"Load failed"<<std::endl;
	        system("pause");
	    }

	    if (!second.loadFromFile("Images/Background.jpg"))
	    {
	        std::cout<<"Load failed"<<std::endl;
	        system("pause");
	    }

	    if (!produceTexture.loadFromFile("Images/Produce.png"))
	    {
	        std::cout<<"Load failed"<<std::endl;
	        system("pause");
	    }

	    if (!meatsTexture.loadFromFile("Images/Meats.png"))
	    {
	        std::cout<<"Load failed"<<std::endl;
	        system("pause");
	    }

	    if (!drinksTexture.loadFromFile("Images/Drinks.png"))
	    {
	        std::cout<<"Load failed"<<std::endl;
	        system("pause");
	    }

	    if (!pharmacyTexture.loadFromFile("Images/Pharmacy.png"))
	    {
	        std::cout<<"Load failed"<<std::endl;
	        system("pause");
	    }

	    if (!grainsTexture.loadFromFile("Images/Grains.png"))
	    {
	        std::cout<<"Load failed"<<std::endl;
	        system("pause");
	    }

	    if (!cosmeticsTexture.loadFromFile("Images/Cosmetics.png"))
	    {
	        std::cout<<"Load failed"<<std::endl;
	        system("pause");
	    }


	    if (!dairyTexture.loadFromFile("Images/Dairy.png"))
	    {
	        std::cout<<"Load failed"<<std::endl;
	        system("pause");
	    }

	    if (!bakeryTexture.loadFromFile("Images/Bakery.png"))
	    {
	        std::cout<<"Load failed"<<std::endl;
	        system("pause");
	    }

	    if (!snacksTexture.loadFromFile("Images/Snacks.png"))
	    {
	        std::cout<<"Load failed"<<std::endl;
	        system("pause");
	    }

	    if (!deliTexture.loadFromFile("Images/Deli.png"))
	    {
	        std::cout<<"Load failed"<<std::endl;
	        system("pause");
	    }

	    if (!hygieneTexture.loadFromFile("Images/Hygiene.png"))
	    {
	        std::cout<<"Load failed"<<std::endl;
	        system("pause");
	    }


	    sf::Sprite entrance;
	    entrance.setPosition(window.getSize().x/2 - 600.0f, 0.0f);
	    entrance.setTexture(initial);

	    sf::Sprite background;
	    background.setTexture(second);

	    sf::Sprite produce;
	    produce.setPosition(window.getSize().x/2 - 500.0f, 500.0f);
	    produce.setTexture(produceTexture);

	    sf::Sprite meats;
	    meats.setPosition(window.getSize().x/2 - 650.0f, 400.0f);
	    meats.setTexture(meatsTexture);

	    sf::Sprite drinks;
	    drinks.setPosition(window.getSize().x/2 - 200.0f, 450.0f);
	    drinks.setTexture(drinksTexture);

	    sf::Sprite pharmacy;
	    pharmacy.setPosition(window.getSize().x/2 - 450.0f, 450.0f);
	    pharmacy.setTexture(pharmacyTexture);

	    sf::Sprite grains;
	    grains.setPosition(window.getSize().x/2 - 225.0f, 450.0f);
	    grains.setTexture(grainsTexture);

	    sf::Sprite cosmetics;
	    cosmetics.scale(0.7,0.7);
	    cosmetics.setPosition(window.getSize().x/2 - 775.0f, 350.0f);
	    cosmetics.setTexture(cosmeticsTexture);

	    sf::Sprite dairy;
	    dairy.scale(0.7,0.7);
	    dairy.setPosition(window.getSize().x/2 - 230.0f, 450.0f);
	    dairy.setTexture(dairyTexture);

	    sf::Sprite bakery;
	    bakery.setPosition(window.getSize().x/2 - 475.0f, 375.0f);
	    bakery.setTexture(bakeryTexture);

	    sf::Sprite snacks;
	    dairy.scale(0.6,0.6);
	    snacks.setPosition(window.getSize().x/2 - 650.0f, 280.0f);
	    snacks.setTexture(snacksTexture);

	    sf::Sprite deli;
	    deli.setPosition(window.getSize().x/2 - 300.0f, 400.0f);
	    deli.setTexture(deliTexture);

	    sf::Sprite hygiene;
	    hygiene.scale(0.8,0.8);
	    hygiene.setPosition(window.getSize().x/2 - 250.0f, 350.0f);
	    hygiene.setTexture(hygieneTexture);

///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////

	TextBox nameBox = TextBox(sf::Vector2f(400,50), sf::Vector2f(window.getSize().x/2 - 400/2, 700.0f) ,5, font, "Enter Full Name");
	TextBox box = TextBox(sf::Vector2f(400,50), sf::Vector2f(window.getSize().x/2 - 400/2, 6.0f) ,5, font, "Search");

	Button produceButton = Button(sf::Vector2f(200,57), sf::Vector2f(5.0f, 5.0f) , font, "Produce", 5, 25, sf::Color::Black, sf::Color::Black );
	Button meatsButton = Button(sf::Vector2f(200,57), sf::Vector2f(5.0f, 72.0f) , font, "Meats", 5, 25, sf::Color::Black, sf::Color::Black);
	Button grainsButton = Button(sf::Vector2f(200,57), sf::Vector2f(5.0f, 139.0f) , font, "Grains", 5, 25, sf::Color::Black, sf::Color::Black);
	Button dairyButton = Button(sf::Vector2f(200,57), sf::Vector2f(5.0f, 206.0f) , font, "Dairy", 5, 25, sf::Color::Black, sf::Color::Black);
	Button drinksButton = Button(sf::Vector2f(200,57), sf::Vector2f(5.0f, 273.0f) , font, "Drinks", 5, 25, sf::Color::Black, sf::Color::Black);
	Button cartButton = Button(sf::Vector2f(100.0f, 45.0f), sf::Vector2f(1095.0f, 20.0f) , font, "Pay", 9, 22, sf::Color::Black, sf::Color::Red);

	Button addToCart = Button(sf::Vector2f(150.0f, 50.0f), sf::Vector2f(600.0f, 100.0f) , font, "Add to Cart", 3, 25, sf::Color::Black, sf::Color::Black);
	Button backButton = Button(sf::Vector2f(100.0f, 45.0f), sf::Vector2f(1095.0f, 20.0f) , font, "Go Back", 9, 22, sf::Color::Black, sf::Color::Red);

	TextBox customerName;
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
                        window.draw(entrance);
    					window.draw(nameBox.getTextBox());
    					window.draw(nameBox.getBoxText());
    					window.display();
    					while(window.waitEvent(event))
    					{
    						if(event.type == sf::Event::TextEntered)
    						{
    							nameBox.textEntered(event.text.unicode);
    							window.clear(sf::Color::White);
                                window.draw(entrance);
    							window.draw(nameBox.getTextBox());
    							window.draw(nameBox.getBoxText());
    							window.display();
    							if(event.text.unicode == 13)	//Must have a particular action be a break statement (<enter> key)
    							{
    								std::cout<<nameBox.getBoxTextStr()<<std::endl;
    								customerName = TextBox(sf::Vector2f(900.0f, 720.0f), erasFont, appendStr("Welcome ", nameBox.getBoxTextStr()), 30, sf::Color::Blue);
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
                window.draw(entrance);
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
                            window.draw(background);
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
        			        window.draw(customerName.getBoxText());
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
        window.draw(background);
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
        window.draw(customerName.getBoxText());
        window.display();
        }

    	}

    	//Construct Produce Frame
    	if(windowDepth == 2)
    	{
    		TextBox produceName = TextBox(sf::Vector2f(0.0f,0.0f), erasFont, appendStr("Name: ",(supermarket.getProduceItem(selectedProduce).getButtonNameStr())), 50, sf::Color::Black);
    		TextBox produceType = TextBox(sf::Vector2f(0.0f,60.0f), erasFont, appendStr("Aisle: ","Produce"), 35, sf::Color::Black);

    		priceUnformatted = appendStr("Price Per Llb: $",(std::to_string(supermarket.getProduceItem(selectedProduce).getPricePerLlb())));
    		characterPos = priceUnformatted.find(".");
			priceFormatted = priceUnformatted.erase(characterPos+3);
    		TextBox producePrice = TextBox(sf::Vector2f(0.0f,100.0f), erasFont, priceUnformatted, 30, sf::Color::Black);

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
    			window.draw(background);
    		    window.draw(produce);
    			window.draw(produceName.getBoxText());
    		    window.draw(produceType.getBoxText());
    			window.draw(producePrice.getBoxText());
    			window.draw(addToCart.getButton());
    			window.draw(addToCart.getButtonName());
    			window.draw(backButton.getButton());
    			window.draw(backButton.getButtonName());

    			window.display();
    		}
    	}



    	if(windowDepth == 37)
    	{
    		supermarket.organizeCartContents();

    		priceUnformatted = appendStr("Total: $",(std::to_string(supermarket.calculateCost())));
    		characterPos = priceUnformatted.find(".");
    		priceFormatted = priceUnformatted.erase(characterPos+3);

    		TextBox total = TextBox( sf::Vector2f(window.getSize().x/2,700.0f), erasFont, priceFormatted, 30, sf::Color::Red);

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

    			window.draw(total.getBoxText());
    			window.display();
    		}
    	}
    }
    return 0;
}

std::string appendStr(std::string str1, std::string str2)
{
	return (str1.append(str2));
}
