#include "Textures.h"

Textures::Textures(const vector<string>& textures)
{
	size_t size = textures.size();

	for (int i = 0; i < size; ++i) {
		m_textures.emplace_back();
		m_textures[i].loadFromFile(textures[i]);
	}
}

const sf::Texture& Textures::getScreen(int num)
{
	static Textures textures(screenNames);

	return textures.m_textures[num];
}

const sf::Texture& Textures::getLevelBackground(int num)
{
	static Textures textures(levelNames);

	return textures.m_textures[num];
}

const sf::Texture& Textures::getUnitTexture(int num, int army) 
{
	static Textures textures(unitNames);

	return textures.m_textures[2*num + army];
}

const sf::Texture& Textures::getWeaponTexture(int num)
{
	static Textures textures(weaponNames);

	return textures.m_textures[num];
}

const sf::Texture& Textures::getGameObjectTexture(int num)
{
	static Textures textures(gameObjectNames);

	return textures.m_textures[num];
}

