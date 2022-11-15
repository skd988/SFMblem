#include "Cursor.h"
#include "Utilities.h"
#include "Consts.h"

Cursor::Cursor(Tile* tile, float size):
	GameObject(Textures::getGameObjectTexture(CURSOR), size, (sf::Vector2f(tile->getLocation()))*size),
	m_tile(tile)
{

}

Unit* Cursor::move(Direction dir)
{
	if (m_tile) {
		Tile* neighbor = m_tile->getNeighbor(dir);
		if (neighbor != nullptr) {
			m_tile = neighbor;
			setPosition(sf::Vector2f(m_tile->getLocation()) * getSize());
		}
		return m_tile->getUnit();
	}
	else
		return nullptr;
}

void Cursor::changeArmy(int army)
{
	setColor(ARMY_COLORS[army]);
}

Tile* Cursor::getTile() const
{
	return m_tile;
}