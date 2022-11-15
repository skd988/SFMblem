#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "Command.h"
#include "Menu.h"
#include "Consts.h"

class Level;

const float COMMAND_HEIGHT = 50;

const sf::Color COMMAND_BLOCK_COLOR(0,  0,  255);//blue
const sf::Color MARKED_COMMAND_COLOR(255, 0, 0);//red
const sf::Color UNMARKED_COMMAND_COLOR(255, 255, 255);//white

using std::vector;
using std::unique_ptr;

class CommandMenu : public Menu {
public:
	//constructor - sets the location of the command menu block.
	CommandMenu(sf::Vector2f location);

	//adds a command to the command menu.
	void add(unique_ptr<Command> command);

	/*
		Draws the menu in the location - a block with the commands names in it.
		The command that is currently chosen is in a different color.
	*/
	virtual void draw(sf::RenderWindow& window) const;

	//returns how many commands are there (size of m_commands)
	virtual int getSize() const;

	//chooses a command - exexcutes it.
	void choose(Level& level) const;

	//marks the chosen command - changes its color to a special (red) one.
	virtual void markSelected();

	//unmarks the chosen command - changes its color to a normal (white) one.
	virtual void unMarkSelected();

private:
	vector<unique_ptr<Command>> m_commands;
	sf::RectangleShape m_command_block;
};