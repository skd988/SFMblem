#pragma once
#include <SFML/Graphics.hpp>
#include <array>

#include "Direction.h"
#include "TilesData.h"

using std::array;

class Unit;

class Tile {
public:
	//Constructor - initiates tile's location and the tile's terrain level.
	Tile(sf::Vector2i location, int terrainLevel);

	//Virtual Destructor - default.
	virtual ~Tile() = default;

	//sets the unit that is in this tile.
	void setUnit(Unit* unit);

	//sets a neighbor tile in the received direction (see m_neighbors).
	void setNeighbor(Tile* neighbor, Direction dir);

	//returns the unit that is in this tile.
	Unit* getUnit() const;

	//returns the neighbor tile that in the received direction (see m_neighbors).
	Tile* getNeighbor(Direction dir) const;

	//returns the terrain level of the tile - how many movement points it takes to pass through it.
	int getTerrainLevel() const;

	//returns the location of the tile.
	sf::Vector2i getLocation() const;

	//returns the distance between this tile and another (according to their location)
	int getDistance(const Tile* tile) const;

private:
	//tiles location on the board.
	sf::Vector2i m_location;

	//tiles terrain level - how many mov
	int m_terrain_level;
	
	//pointer to the unit on this tile.
	Unit* m_unit;

	//pointers to the neighbors of the tile (according to directions)
	array<Tile*, NUM_OF_DIRECTIONS> m_neighbors;
};