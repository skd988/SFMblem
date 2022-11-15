#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Level;

using std::string;

const int COMMAND_FONT_SIZE = 20;

class Command {
public:
	//Constructor - initiates command's name.
	Command(string name);

	//initiates the text style of the command.
	void initText();

	//sets the command position.
	void setPosition(sf::Vector2f origin);

	//draws the command (the text of the command) on the window.
	void draw(sf::RenderWindow& window) const;

	//sets the text color.
	void setTextColor(const sf::Color& color);

	//executes the command (on a level).
	virtual void execute(Level& level) = 0;

private:
	//text of the command (name).
	sf::Text m_text;
};