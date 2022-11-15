#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <memory>

#include "Tile.h"

using std::unique_ptr;
using std::make_unique;
using std::ifstream;
using std::vector;
using std::string;

class Board {
public:
	/*
		Consturcor - receives levels file to read the level from,
		and sets the tile size according to window size and number of tiles
	*/
	Board(ifstream& levels_file, sf::Vector2u window_size);
	
	//returns the tile at the location.
	Tile* getTile(sf::Vector2i location) const;
	
	//returns the tile size.
	float getTileSize() const;

	//returns the size of the board
	sf::Vector2i getSize() const;

private:
	//returns whether a received location is valid (exists in the board)
	bool isValid(sf::Vector2i location) const;

	//updates the neighbors of each tile in the board.
	void updateNeighbors();

	//updates a spcific tile in the board.
	void updateTileNeighbors(sf::Vector2i location);

	//a matrix of tiles (unique_ptr).
	vector<vector<unique_ptr<Tile>>> m_board;

	//tile size - both height and length (each tile is a square)
	float m_tile_size;
};