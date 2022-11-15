#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>

#include "Board.h"

#include "UnitsData.h"
#include "Textures.h"

#include "GameObject.h"
#include "CommandMenu.h"
#include "UnitDataBlock.h"
#include "Cursor.h"
#include "Consts.h"

using std::ifstream;

const sf::Color DATA_BLOCK_COLOR(128, 128, 128);//gray

class Level {
public:
	/*
		Constructor - receives level's number, a path to read the file from,
		and a window.

		initiates board and m_armys according to the file (of level_num),
		loads background of the level and sets the window size according to that picture.
	
	*/
	Level(int level_num, sf::RenderWindow& window);
	
	/*
		runs the level - main game loop:
		runs while both armies have alive units.
		switches between the armies once all the units have moved.
		lets the user move the cursor around, choose a unit,
		and move him to a different tile. there, he can do actions such
		as attack another unit and etc.
	*/
	int run();

	int playTurn(int army);

	/*
		draws the background, the units
		and all other game components on the window.	
	*/
	void draw();

	//returns whether and which army has won (-1 if none)
	int isArmyDead() const;

	//deletes a unit from the m_armys.
	void deleteUnit(const Unit* unit);

	//returns the window of the level.
	sf::RenderWindow& getWindow() const;

private:
	/*
		opens the file according to level's num. 
		return reference to m_levels_file (for initializing)
	
	*/
	ifstream& openLevelFile(int level_num);

	/*
		initates army according to num of soldiers and army num,
		reading from levels_file.
	*/
	void initArmy(int numOfSoldiers, int armyNum);

	/*
		adapts window size from the background picture
		and the length of the data block.
		return reference to m_window (for initializing).
	*/
	sf::RenderWindow& adaptWindow(sf::RenderWindow& window);

	//levels_num.
	int m_level_num;

	//background of the level.
	sf::Sprite m_background;

	//levels file to read from.
	ifstream m_levels_file;

	//window of the game
	sf::RenderWindow& m_window;

	//game's board.
	Board m_board;

	//currently chosen unit.
	Unit* m_chosen;

	//currently pointed at unit.
	Unit* m_pointed;

	//cursor of the game, moved by arrow keys.
	Cursor m_cursor;

	//tells data about the currently pointed unit.
	UnitDataBlock m_unit_data_block;

	//vector of the two armys - each consists of Units.
	vector <vector<unique_ptr<Unit>>> m_armys;
};