#include "Utilities.h"
#include <time.h>

void setSpriteSize(sf::Sprite& sprite, sf::Vector2f size)
{
	sf::FloatRect currentSize = sprite.getLocalBounds();
	sprite.setScale(sf::Vector2f(size.x / currentSize.width, size.y / currentSize.height));
}

const sf::Font& getFont()
{
	static bool isInit = false;
	static sf::Font font;
	if (!isInit) {
		font.loadFromFile("C:/Windows/Fonts/Verdana.ttf");
		isInit = true;
	}
	return font;
}

int randRange(int min, int max)
{
	static bool isInit = false;
	if (!isInit) {
		srand(time(NULL));
		isInit = true;
	}

	if (max < min)
		return 0;

	return (rand() %  (max - min + 1)) + min ;
}

void exitProgram(sf::RenderWindow& window)
{
	window.close();
	exit(EXIT_SUCCESS);
}

sf::Music& getMainMusic()
{
	static sf::Music mainMusic;
	static bool isInit = false;
	if (!isInit) {
		if (!mainMusic.openFromFile("mainMusic.ogg"))
			exit(EXIT_FAILURE); // error
		isInit = true;
	}
	return mainMusic;
}

sf::Music& getBackgroundMusic()
{
	static sf::Music backgroundMusic;
	static bool isInit = false;
	if (!isInit) {
		if (!backgroundMusic.openFromFile("backgroundMusic.ogg"))
			exit(EXIT_FAILURE); // error
		isInit = true;
	}
	return backgroundMusic;
}

sf::Music& getBattleMusic()
{
	static sf::Music battleMusic;
	static bool isInit = false;
	if(!isInit){
		if (!battleMusic.openFromFile("battleMusic.ogg"))
			exit(EXIT_FAILURE); // error
		isInit = true;
	}
	return battleMusic;
}

sf::Music& getLevelPassedMusic()
{
	static sf::Music levelPassedMusic;
	static bool isInit = false;
	if (!isInit) {
		if (!levelPassedMusic.openFromFile("levelPassedMusic.ogg"))
			exit(EXIT_FAILURE); // error
		isInit = true;
	}
	return levelPassedMusic;
}

sf::Music& getWinningMusic()
{
	static sf::Music winningMusic;
	static bool isInit = false;
	if (!isInit) {
		if (!winningMusic.openFromFile("winningMusic.ogg"))
			exit(EXIT_FAILURE); // error
		isInit = true;
	}
	return winningMusic;
}




