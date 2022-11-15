#include "Controller.h"
#include "Textures.h"
#include "Utilities.h"
#include "SFML/Audio.hpp"

Controller::Controller() :
	m_window(sf::VideoMode(WINDOW_LENGTH, WINDOW_HEIGHT), "SFMblem")
{
	m_window.setPosition({ 200,30 });
}

void Controller::run()
{
	std::array<int, NUM_OF_ARMYS> score = { 0, 0 };
	int winningArmy;
	mainMenuScreen();
	for (int level_num = 0; level_num < LEVEL_NAMES.size(); ++level_num)
	{
		Level level(level_num, m_window);
		winningArmy = level.run();
		++score[winningArmy];
		m_window.setSize({ WINDOW_LENGTH, WINDOW_HEIGHT });
		levelPassedScreen(winningArmy);
	}

	gameWonScreen(score);
	
}

void Controller::mainMenuScreen()
{
	sf::Sprite sprite(Textures::getScreen(0));
	m_window.setSize({ unsigned int(sprite.getGlobalBounds().width), unsigned int(sprite.getGlobalBounds().height) });
	m_window.clear(sf::Color::Blue);
	m_window.draw(sprite);
	m_window.display();
	getMainMusic().play();
	waitForEnter();
	getMainMusic().stop();
}

void Controller::levelPassedScreen(int winningArmy)
{
	getLevelPassedMusic().play();
	m_window.clear(sf::Color::Green);
	sf::Text text("Level won by " + ARMY_NAMES[winningArmy], getFont(), FONT_SIZE);
	text.setColor(ARMY_COLORS[winningArmy]);
	text.setPosition(sf::Vector2f((WINDOW_LENGTH - text.getGlobalBounds().width) / 2, WINDOW_HEIGHT / 2) );
	
	m_window.draw(text);
	m_window.display();
	waitForEnter();
	getLevelPassedMusic().stop();
}

void Controller::gameWonScreen(std::array<int, NUM_OF_ARMYS> score)
{
	getWinningMusic().play();
	m_window.clear(sf::Color::Green);
	sf::Text text("", getFont(), FONT_SIZE);

	if (score[BLUE_ARMY] > score[RED_ARMY]) {
		text.setString("Blue Army Won!");
		text.setColor(ARMY_COLORS[BLUE_ARMY]);
	}
	else if (score[RED_ARMY] > score[BLUE_ARMY]) {
		text.setString("Red Army Won!");
		text.setColor(ARMY_COLORS[RED_ARMY]);
	}
	else {
		text.setString("It's a Tie!");
		text.setColor(ARMY_COLORS[BLUE_ARMY] + ARMY_COLORS[RED_ARMY]);
	}

	text.setPosition(sf::Vector2f((WINDOW_LENGTH - text.getGlobalBounds().width) / 2, WINDOW_HEIGHT / 2));

	m_window.draw(text);
	m_window.display();
	waitForEnter();
}

void Controller::waitForEnter()
{
	sf::Event event;
	bool shouldBreak = false;
	while (!shouldBreak && m_window.waitEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			exitProgram(m_window);

		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Enter)
				shouldBreak = true;
			break;
		}
	}
}