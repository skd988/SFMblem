#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

using std::vector;
using std::string;

const vector<string> screenNames = { "mainMenu.png" };
const vector<string> levelNames = { "level1.png", "level2.png", "level3.png" };
const vector<string> unitNames = { "blueArmySoldier.png", "redArmySoldier.png", "blueArmyArcher.png", "redArmyArcher.png", "blueArmyCavalier.png", "redArmyCavalier.png", "blueArmyKnight.png", "redArmyKnight.png", "blueArmyBishop.png", "redArmyBishop.png", "blueArmyMage.png", "redArmyMage.png" };
const vector<string> weaponNames = { "Sword.png", "Bow.png", "Lance.png", "Stuff.png", "SpellBook.png"};
const vector<string> gameObjectNames = { "Cursor.png" };

class Textures {
public:
	//class is multiton - no public constructor available
	Textures(const Textures&) = delete;
	
	//returns picture of a requested string
	static const sf::Texture& getScreen(int num);

	//returns texture of a requested level background.
	static const sf::Texture& getLevelBackground(int num);

	//returns texture of a requested unit, according to its army.
	static const sf::Texture& getUnitTexture(int num, int army);

	//returns texture of a requested weapon.
	static const sf::Texture& getWeaponTexture(int num);

	//returns texture of a requested other GameObject.
	static const sf::Texture& getGameObjectTexture(int num);

private:
	//game textures
	vector<sf::Texture> m_textures;

	//will be called only from get..Texture
	Textures(const vector<string>& textures);
};