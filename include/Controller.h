#pragma once

#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Unit.h"
#include <vector>
#include <string>
#include <fstream>

#include "Textures.h"
#include "Level.h"
#include "Consts.h"

using std::ifstream;
using std::string;
using std::vector;

const int WINDOW_LENGTH = 1000;
const int WINDOW_HEIGHT = 550;const float FONT_SIZE = 50;
class Controller {
public:
	//Consructor - initiates m_window.
	Controller();

	/*
		runs the game, each time initiates a new level
		according to level files, and runs it.
		at the end announces the winner of the game (red/blue army)
	*/
	void run();

private:
	//shows main menu screen.
	void mainMenuScreen();

	//shows levels passed screen.
	void levelPassedScreen(int winningArmy);

	//shows game ending screen.
	void gameWonScreen(std::array<int, NUM_OF_ARMYS> score);

	//waits for enter - each screen only exits once enter is pressed.
	void waitForEnter();

	//the window of the game.
	sf::RenderWindow m_window;
};