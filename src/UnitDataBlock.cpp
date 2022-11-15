#include "UnitDataBlock.h"
#include "Unit.h"
#include "Utilities.h"

UnitDataBlock::UnitDataBlock(sf::Vector2f location, float length) :
	m_rect({ length, UNIT_DATA_BLOCK_HEIGHT * 1.2 })
{
	m_rect.setPosition(location);
	m_rect.setFillColor(sf::Color::Green);
	for (int i = 0; i < NUM_OF_INFOS; ++i) {
		m_texts.push_back({});
		m_texts[i].setFillColor(sf::Color::Black);
		m_texts[i].setFont(getFont());
		m_texts[i].setCharacterSize(DATA_BLOCK_FONT_SIZE);
		m_texts[i].setPosition(m_rect.getPosition() + sf::Vector2f(0, i * DATA_BLOCK_FONT_SIZE));
	}
}

void UnitDataBlock::update(const Unit* unit)
{
	if (unit != nullptr) {
		m_texts[0].setString(CLASS + unit->getClass());
		m_texts[1].setString(HP + std::to_string(unit->getCurrHp()) + "/" + std::to_string(unit->getStats().m_maxHp));
	}
}
void UnitDataBlock::draw(sf::RenderWindow& window) const
{
	window.draw(m_rect);
	for (auto& info : m_texts)
		window.draw(info);
}
