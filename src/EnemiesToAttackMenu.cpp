#include "EnemiesToAttackMenu.h"

EnemiesToAttackMenu::EnemiesToAttackMenu(vector<Unit*>& enemies) :
	m_enemies(std::move(enemies))
{
	if (m_enemies.size() > 0) {
		sf::RectangleShape rect({ m_enemies[0]->getSize(), m_enemies[0]->getSize() });
		rect.setFillColor(sf::Color::Transparent);
		rect.setOutlineColor(sf::Color::Yellow);
		rect.setOutlineThickness(3.5);

		for (int i = 0; i < m_enemies.size(); ++i) {
			m_rectangles.push_back(rect);
			m_rectangles[i].setPosition(m_enemies[i]->getPosition());
		}
	}
	this->markSelected();
}

void EnemiesToAttackMenu::draw(sf::RenderWindow& window) const
{
	for (auto& rect : m_rectangles)
		window.draw(rect);
}

int EnemiesToAttackMenu::getSize() const
{
	return m_enemies.size();
}

Unit* EnemiesToAttackMenu::getChosenEnemy() const
{
	if (inRange())
		return m_enemies[getChosen()];
	else
		;
}

void EnemiesToAttackMenu::markSelected()
{
	if (inRange())
		m_rectangles[getChosen()].setOutlineColor(MARKED_ENEMY_COLOR);
}

void EnemiesToAttackMenu::unMarkSelected()
{
	if (inRange())
		m_rectangles[getChosen()].setOutlineColor(UNMARKED_ENEMY_COLOR);
}


