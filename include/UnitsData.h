#pragma once
#include <array>
#include <string>
#include "WeaponsData.h"

using std::array;
using std::string;

const int NUM_OF_UNITS = 6; 

//struct that contains all of the stats of a unit.
struct UnitStats {
	int m_movement;
	int m_attack;
	int m_defense;
	int m_skill;
	int m_speed;
	int m_maxHp;
	UnitStats(int movement, int attack, int skill, int speed, int defense, int maxHp) : m_movement(movement), m_attack(attack), m_skill(skill), m_speed(speed), m_defense(defense), m_maxHp(maxHp) {}
};

enum UnitNum {SOLDIER, ARCHER, CAVALIER, KNIGHT, BISHOP, MAGE};

const array<UnitStats, NUM_OF_UNITS> UNIT_STATS = { UnitStats(5,6,11,12,4,19), UnitStats(5,3,3,4,3,17), UnitStats(7,5,2,5,6,20), UnitStats(4,5,2,5,0,17), UnitStats(5,1,2,2,0,16), UnitStats(5,1,2,2,3,16) };
const array<string, NUM_OF_UNITS> UNIT_NAMES = { "Soldier", "Archer", "Cavalier", "Knight", "Bishop", "Mage"};
const array<char, NUM_OF_UNITS> UNIT_CHAR = { 'S', 'A', 'C', 'K', 'H', 'M' };
const array<array<bool, NUM_OF_WEAPONS>, NUM_OF_UNITS> WEAPON_SKILLS = { (1,0,0,0,0), (0,1,0,0,0),(1,0,1,0,0),(0,0,1,0,0),(0,0,0,1,0),(0,0,0,0,1) };