#include "Wall.h"

Wall::Wall(sf::Vector2i location) :
	Tile(location, TILE_TERRAIN_LEVEL[WALL])
{
}