#include "CommandMenu.h"
#include "UnitAction.h"

CommandMenu::CommandMenu(sf::Vector2f location) :
	m_command_block({ DATA_BLOCK_LENGTH, 0 })
{
	this->markSelected();

	m_command_block.setPosition(location);
	m_command_block.setFillColor(COMMAND_BLOCK_COLOR);
}

void CommandMenu::add(unique_ptr<Command> command)
{
	command->setPosition({ m_command_block.getPosition().x, float(m_commands.size() * COMMAND_HEIGHT) });
	command->setTextColor(UNMARKED_COMMAND_COLOR);
	m_commands.emplace_back(std::move(command));
	m_command_block.setSize({ DATA_BLOCK_LENGTH, COMMAND_HEIGHT * m_commands.size() });
	this->markSelected();
}

void CommandMenu::draw(sf::RenderWindow& window) const
{
	window.draw(m_command_block);
	for (auto& command : m_commands)
		command->draw(window);
}

int CommandMenu::getSize() const
{
	return m_commands.size();
}

void CommandMenu::choose(Level& level) const
{
	if (inRange())
		m_commands[getChosen()]->execute(level);
	else
		;//throw?
}

void CommandMenu::markSelected()
{
	if(inRange())
		m_commands[getChosen()]->setTextColor(MARKED_COMMAND_COLOR);
}

void CommandMenu::unMarkSelected()
{
	if (inRange())
		m_commands[getChosen()]->setTextColor(UNMARKED_COMMAND_COLOR);
}