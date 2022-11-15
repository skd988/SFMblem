#include "Command.h"
#include "Utilities.h"

Command::Command(string name)
{
	m_text.setString(name);
	initText();
}

void Command::initText()
{
	m_text.setStyle(sf::Text::Bold);
	m_text.setCharacterSize(COMMAND_FONT_SIZE);
	m_text.setFont(getFont());
}

void Command::setPosition(sf::Vector2f origin)
{
	m_text.setPosition(origin);
}
void Command::draw(sf::RenderWindow& window) const
{
	window.draw(m_text);
}

void Command::setTextColor(const sf::Color& color)
{
	m_text.setFillColor(color);
}