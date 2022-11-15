#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class Unit;
using std::string;
using std::vector;

const string CLASS = "Class: ";
const string HP = "Hp: ";
const int DATA_BLOCK_FONT_SIZE = 20;
const int NUM_OF_INFOS = 2;
const int UNIT_DATA_BLOCK_HEIGHT = NUM_OF_INFOS * DATA_BLOCK_FONT_SIZE * 1.2;

class UnitDataBlock {
public:
	//Constructor - initiates the location and length of the data block.
	UnitDataBlock(sf::Vector2f location, float length);

	//updates the data block's unit.
	void update(const Unit* unit);

	//draws the data block over a window.
	void draw(sf::RenderWindow& window) const;

private:
	//rectangle of the data block.
	sf::RectangleShape m_rect;

	//texts of the infos of the data block.
	vector<sf::Text> m_texts;
};