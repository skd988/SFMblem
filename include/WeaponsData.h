#pragma once

#include <array>
#include <string>

using std::array;
using std::string;

const int NUM_OF_WEAPONS = 5;

//struct that contains all of the stats of a weapon.
struct WeaponStats {
	int m_damage;
	int m_hitChance;
	int m_minRange;
	int m_maxRange;
	WeaponStats(int damage, int hitChance, int minRange, int maxRange) : m_damage(damage), m_hitChance(hitChance), m_minRange(minRange), m_maxRange(maxRange) {}
};


enum WeaponNum {SWORD, BOW, LANCE, STUFF, SPELL_BOOK};

const array<WeaponStats, NUM_OF_WEAPONS> WEAPON_STATS = { WeaponStats(5, 90, 1, 1), WeaponStats(6, 65, 2, 2), WeaponStats(7, 80, 1, 1), WeaponStats(8, 90, 1, 1), WeaponStats(5, 90, 1, 2) };
const array<string, NUM_OF_WEAPONS> WEAPON_NAMES = { "Sword", "Bow", "Lance" "Stuff", "SpellBook" };