#pragma once

#include "Tile.h"

class Empty : public Tile {
public:
	/*
		Constructor - initiates Tile with received location,
		and terrain level for Empty.
	*/
	Empty(sf::Vector2i location);

private:

};