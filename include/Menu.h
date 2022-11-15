#pragma once

#include <SFML/Graphics.hpp>

class Level;

class Menu {
public:
	//Constructor - sets m_chosen to 0 (first)
	Menu();

	//Virtual Destructor - default
	virtual ~Menu() = default;

	/*
		runs menu - lets you move m_chosen up and down (with arrow keys). 
		Chooses with Z, cancels choose with X.
		returns whether the user chose (Z), or cancels (X).
	*/
	bool run(Level& level);


	//returns the m_chosen
	int getChosen() const;

	//returns whether m_chosen is in the range of the menu (between 0 and size)
	bool inRange() const;

	/*
		moves m_chosen up and down in the menu - receives whether move up (-) or down (+). 
		Circles if reaches the end.
	*/
	bool moveChosen(bool isUp);
	
	//draws the menu - each menu has a different graphical display.
	virtual void draw(sf::RenderWindow& window) const = 0;
	
	//returns the size of the menu - each menu has a different data sturcture.
	virtual int getSize() const = 0;

	//marks the chosen option - each according to its graphical display.
	virtual void markSelected() = 0;

	//unmarks the chosen option - each according to its graphical display.
	virtual void unMarkSelected() = 0;

private:
	//the currently chosen option
	int m_chosen;
};