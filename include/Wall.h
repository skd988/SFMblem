#pragma once

#include "Tile.h"

class Wall : public Tile {
public:
	/*
		Constructor - initiates Tile with received location,
		and terrain level for Wall.
	*/
	Wall(sf::Vector2i location);

private:

};