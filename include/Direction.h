#pragma once

#include <SFML/Graphics.hpp>
#include <array>

using std::array;

const int NUM_OF_DIRECTIONS = 4;

enum Direction { RIGHT, DOWN, LEFT, UP };

//how to move on the matrix for each direction.
const array<sf::Vector2i, NUM_OF_DIRECTIONS> DIRECTIONS = { sf::Vector2i(1, 0), sf::Vector2i(0, 1), sf::Vector2i(-1, 0), sf::Vector2i(0, -1) };