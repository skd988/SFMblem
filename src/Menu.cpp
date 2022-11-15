#include "Menu.h"
#include "Utilities.h"
#include "Level.h"

Menu::Menu() :
	m_chosen(0)
{
}

bool Menu::run(Level& level)
{
	sf::RenderWindow& window = level.getWindow();
	while (true) {
		level.draw();
		this->draw(window);
		window.display();

		if (auto event = sf::Event{}; window.waitEvent(event)) {
			if (event.type == sf::Event::Closed){
				exitProgram(window);
			}
			else if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Up)
					moveChosen(true);

				else if (event.key.code == sf::Keyboard::Down)
					moveChosen(false);

				else if (event.key.code == sf::Keyboard::Z)
					return true;

				else if (event.key.code == sf::Keyboard::X)
					return false;
			}
		}
	}
}

int Menu::getChosen() const
{
	return m_chosen;
}

bool Menu::inRange() const
{
	return 0 <= m_chosen && m_chosen < this->getSize();
}

bool Menu::moveChosen(bool isUp)
{
	this->unMarkSelected();

	m_chosen = ((m_chosen + (isUp ? -1 : 1)) + this->getSize()) % this->getSize();

	this->markSelected();
	return true;
}