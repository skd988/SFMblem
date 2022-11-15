#include "Tile.h"

Tile::Tile(sf::Vector2i location, int terrainLevel) :
	m_unit(nullptr),
	m_neighbors(),
	m_location(location),
	m_terrain_level(terrainLevel)
{
	for (auto neighbor : m_neighbors)
		neighbor = nullptr;
}

sf::Vector2i Tile::getLocation() const
{
	return m_location;
}

void Tile::setNeighbor(Tile* neighbor, Direction dir)
{
	m_neighbors[dir] = neighbor;
}

Tile* Tile::getNeighbor(Direction dir) const
{
	return m_neighbors[dir];
}

int Tile::getTerrainLevel() const
{
	return m_terrain_level;
}

void Tile::setUnit(Unit* unit)
{
	m_unit = unit;
}

Unit* Tile::getUnit() const
{
	return m_unit;
}

int Tile::getDistance(const Tile* tile) const
{
	sf::Vector2i loc = tile->getLocation();
	return abs(m_location.x - loc.x) + abs(m_location.y - loc.y);
}