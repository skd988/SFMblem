#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
//constants that are relavent to multiple classes

using std::string;
using std::vector;

enum Army { BLUE_ARMY, RED_ARMY };

const int NUM_OF_ARMYS = 2;
const vector<string> ARMY_NAMES = { "Blue Army", "Red Army" };
const vector<sf::Color> ARMY_COLORS = { sf::Color(0, 0, 255), sf::Color(255, 0, 0)};
const int DATA_BLOCK_LENGTH = 200;

const std::vector<string> LEVEL_NAMES = { "level1.txt", "level2.txt", "level3.txt" };