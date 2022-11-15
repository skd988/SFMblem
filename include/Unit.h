#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include <vector>
#include <array>
#include <unordered_map>
#include "GameObject.h"
#include "Item.h"
#include "Tile.h"
#include "Textures.h"
#include "UnitsData.h"

using std::string;
using std::vector;
using std::array;
using std::unordered_map;
using std::make_unique;
using std::unique_ptr;

class Board;
class CommandMenu;
class Weapon;

const sf::Color RANGE_COLOR(0, 0, 255, 180);

const int CHANGE_HEALTH_FONT_SIZE = 40;

const int MISS = -1;
const int CANT_DAMAGE = -2;

const sf::Color SLEEP_COLOR(127, 127, 127);//grayish

class Unit : public GameObject {
public:
	/*
		Constructor - initiates all of unit parameters, such as texture, name of class, location and stats.		
	*/
	Unit(string classOfUnit, float size, const sf::Texture& texture, int army, const array<bool, NUM_OF_WEAPONS>& weapons_skill, Tile* location, UnitStats stats);
	
	/*
		updates the units tile range (m_tile_range) according to its movement points 
		and its location. (see readme for implementation details)
	*/
	void updateTileRange();

	
	//makes an encounter with an enemy unit. both inflicting damage to each other, (see damage function)
	void EncounterEnemy(sf::RenderWindow& window, Unit* unit);

	//returns whether this unit's HP <= 0
	bool isDead() const;

	/*
		changes unit health according to offset. 
		cannot heal above maxHp.
	*/
	void changeHealth(int offset);

	//moves the unit to another tile, if it's in the range.
	bool move(Tile* destination);

	/*
		returns the command menu of the unit,
		the commands that this unit can do in this tile.
		always adds "wait" (do nothing),
		and if there are any enemies in range, 
		adds "attack"
	*/
	CommandMenu getCommandMenu(const Board& board, sf::Vector2f location);

	//paints the range of the units in a color (RANGE_COLOR).
	void drawRange(sf::RenderWindow& window) const;

	//returns the army of this unit.
	int getArmy() const;

	//returns the class name of this unit.
	string getClass() const;

	//returns the stats of this unit.
	UnitStats getStats() const;

	//returns the current HP of this unit
	int getCurrHp() const;

	/*
		returns the enemies that are in the range of the 
		weapon equipped by this unit.	
	*/
	vector<Unit*> getEnemiesInRange(const Board& board);

	/*
		prints the damage inflicted to this unit,
		stays for a few miliseconds.
	*/
	void printDamage(sf::RenderWindow& window, int damage);

	//returns whether the unit is idle (moved this turn)
	bool isIdle() const;

	//wakes the unit - it can move again (also changes its color to normal
	void wake();

	//puts the unit to sleep - it cant move (also changes its color to gray)
	void sleep();

	//returns the tile of that the unit is at.
	Tile* getTile() const;

	/*
		adds an item to the unit. 
		if the item is a weapon and there is no weapon equipped,
		sets m_weapon_equipped to it.
	*/
	void addItem(unique_ptr<Item> item);

	//tells the unit to die - remove itself from the tile.
	void die();

private:
	/*
		tries to damage an enemy, returns the damage inflicted/other possible outcomes:
		first checks whether there is a weapon equipped,
		and whether the enemy is in the range of the weapon.
		if one of those is false, returns CANT_ATTACK (-2).

		then, calculates the hit chance according to the following formula:
			hitChance = weapon.hitChance + thisUnit.skill - enemy.speed

		randomizes whether the unit hit, if not, returns MISS (-1).
		if yes, calculates the damage according to the following formula:
			damage = weapon.damage + thisUnit.attack - enemy.defense
		inflicts the damage to the enemy, and returns it.
	*/
	int Damage(Unit* enemy);

	/*
		tries to add an enemy to the enemy range, 
		if the tile indeed contains an enemy unit.
	*/
	void tryAddEnemy(vector<Unit*>& enemy_range, Tile* tile);

	/*
		recursive function to calculate tile range, called from updateTileRange (see readme).
	*/
	void updateTileRangeRec(Tile* currentTile, Tile* destTile, int movement);

	//unit's class name
	string m_class;

	//unit's items
	vector<unique_ptr<Item>> m_items;

	//a pointer to the weapon currently equipped.
	Weapon* m_weapon_equipped;

	//which weapons can this unit use.
	array <bool, NUM_OF_WEAPONS> m_weapons_skill;
	
	//the tile this unit is at.
	Tile* m_location;

	//a text to represent the health change (inflicted damage).
	sf::Text m_healthChange;

	//the rectangle of the tile range.
	sf::RectangleShape m_range_rect;

	//whether this unit already moved this turn.
	bool m_idle;

	//unit's army
	int m_army;

	//unit's current HP
	int m_currHp;
	
	//unit's stats
	UnitStats m_stats;

	/*
		unit's tile range (where it can move),
		consists of a map where
		first - the tile the unit wants to move to
		second - a pair consists of the unit needs to get to get to this tile,
				and how many movement points it takes to get here.
	*/
	unordered_map<Tile*, std::pair<Tile*,int> > m_tile_range;
};