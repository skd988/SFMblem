#pragma once

#include <array>
#include <string>

using std::array;
using std::string;

const int NUM_OF_TILES = 6;

enum TileNum { EMPTY, BRIDGE, WALL, RIVER, MOUNTAIN, FOREST };

const array<char, NUM_OF_TILES> TILE_CHAR = { ' ', '-', '#', '~', '^', '*' };

const array<int, NUM_OF_TILES> TILE_TERRAIN_LEVEL = { 1,1,-1,-1,2,2 };
