#pragma once

#include "Item.h"
#include "WeaponsData.h"
#include "Textures.h"

class Weapon : public Item {
public:
	/*
		Constructor - initiates Item with its texture and name, 
		as well with the weapon stats.
	*/
	Weapon(const sf::Texture& texture, WeaponStats stats, string name);

	//returns the weapon stats.
	WeaponStats getStats() const;

private:
	WeaponStats m_stats;
};