#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

//sets sprite size
void setSpriteSize(sf::Sprite& sprite, sf::Vector2f size);

//returns a random number between min and max
int randRange(int min, int max);

//closes window and exists.
void exitProgram(sf::RenderWindow& window);

//returns the font of the program.
const sf::Font& getFont();

//returns main menu music.
sf::Music& getMainMusic();

//returns the background game music.
sf::Music& getBackgroundMusic();

//returns the battle music.
sf::Music& getBattleMusic();

//returns the level passed music.
sf::Music& getLevelPassedMusic();

//returns the winning music.
sf::Music& getWinningMusic();
