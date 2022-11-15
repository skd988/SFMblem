#pragma once

#include <SFML/Graphics.hpp>

#include "Menu.h"
#include "Unit.h"

const sf::Color MARKED_ENEMY_COLOR(255, 0, 0);//red
const sf::Color UNMARKED_ENEMY_COLOR(255, 255, 0);//yellow

class EnemiesToAttackMenu : public Menu {
public:
	/*
		Constructor - receives list of enemies as the list,
		and initiates m_enemies (enemies in range to attack) 
		and indicator rectangle around each one.
	*/
	EnemiesToAttackMenu(vector<Unit*>& enemies);

	/*
		draws the menu - draws a rectangle 
		around each of the enemies in range,
		the enemy that is currently chosen is marked with red.
	*/
	virtual void draw(sf::RenderWindow& window) const;

	//returns the size of m_enemies - how many enemies are in range.
	virtual int getSize() const;

	//returns the currently chosen enemy in the menu.
	Unit* getChosenEnemy() const;

	//marks the chosen enemy - changes its rectangle's color to a special (red) one.
	virtual void markSelected();

	//unmarks the chosen enemy - changes its rectangle's color to a special (yellow) one.
	virtual void unMarkSelected();

private:
	//enemies that are in range.
	vector<Unit*> m_enemies;

	//rectangle indicators of each enemy.
	vector<sf::RectangleShape> m_rectangles;
};