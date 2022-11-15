#include "Soldier.h"
#include "Sword.h"

Soldier::Soldier(float size, int army, Tile* location) :
	Unit(UNIT_NAMES[SOLDIER], size, Textures::getUnitTexture(SOLDIER,army), army, WEAPON_SKILLS[SOLDIER], location, UNIT_STATS[SOLDIER])
{
	addItem(make_unique<Sword>());
}