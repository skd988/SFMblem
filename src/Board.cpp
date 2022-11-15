#include "Board.h"

#include <fstream>

#include "TilesData.h"
#include "Empty.h"
#include "Bridge.h"
#include "Wall.h"
#include "River.h"
#include "Mountain.h"
#include "Forest.h"

Board::Board(ifstream& levels_file, sf::Vector2u window_size)
{
	char type = 0;
	int col, row;
	for (row = 0; type != 'E'; ++row) {
		m_board.emplace_back();
		for (type = levels_file.get(), col = 0; type != 'E' && type != '\n'; ++col, type = levels_file.get()) {
			if (type == TILE_CHAR[EMPTY])
				m_board[row].emplace_back(make_unique<Empty>(sf::Vector2i(col, row)));
			else if (type == TILE_CHAR[BRIDGE])
				m_board[row].emplace_back(make_unique<Bridge>(sf::Vector2i(col, row)));
			else if (type == TILE_CHAR[WALL])
				m_board[row].emplace_back(make_unique<Wall>(sf::Vector2i(col, row)));
			else if (type == TILE_CHAR[RIVER])
				m_board[row].emplace_back(make_unique<River>(sf::Vector2i(col, row)));
			else if (type == TILE_CHAR[MOUNTAIN])
				m_board[row].emplace_back(make_unique<Mountain>(sf::Vector2i(col, row)));
			else if (type == TILE_CHAR[FOREST])
				m_board[row].emplace_back(make_unique<Forest>(sf::Vector2i(col, row)));
		}
	}

	m_tile_size = window_size.y / m_board.size();

	updateNeighbors();
}

Tile* Board::getTile(sf::Vector2i location) const
{
	return isValid(location) ? m_board[location.y][location.x].get() : nullptr;
}

bool Board::isValid(sf::Vector2i location) const
{
	return 0 <= location.y && location.y < m_board.size() && 0 <= location.x && location.x < m_board[location.y].size();
}

void Board::updateNeighbors()
{
	for (int i = 0; i < m_board.size(); ++i)
	{
		for (int j = 0; j < m_board[i].size(); ++j)
			updateTileNeighbors({ j, i });
	}
}

void Board::updateTileNeighbors(sf::Vector2i location)
{
	if (isValid(location))
		for (int dir = 0; dir < NUM_OF_DIRECTIONS; ++dir)
			m_board[location.y][location.x]->setNeighbor(getTile(location + DIRECTIONS[dir]), Direction(dir));
}


float Board::getTileSize() const
{
	return m_tile_size;
}

sf::Vector2i Board::getSize() const
{
	return sf::Vector2i(m_board[0].size(), m_board.size());
}
