#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Direction.h"
#include "Unit.h"
#include "Tile.h"

class Cursor : public GameObject {
public:
	/*
		Constructor - initiates GameObject with size, texture and location (according to the received tile),
		as well as m_tile with the received tile.	
	*/
	Cursor(Tile* tile, float size);

	/*
		moves the cursor to another tile (while updating its location)
		according to a received direction (using the neighbors of the current tile).	
	*/
	Unit* move(Direction dir);
	
	//changes cursor army (whose turn it is).
	void changeArmy(int army);

	//returns the tile the cursor is currently on.
	Tile* getTile() const;

private:
	//the tile the cursor is on.
	Tile* m_tile;
};