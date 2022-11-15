#include "Empty.h"

Empty::Empty(sf::Vector2i location) :
	Tile(location, TILE_TERRAIN_LEVEL[EMPTY])
{
}