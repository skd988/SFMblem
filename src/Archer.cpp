#include "Archer.h"
#include "Bow.h"

Archer::Archer(float size, int army, Tile* location) :
	Unit(UNIT_NAMES[ARCHER], size, Textures::getUnitTexture(ARCHER, army), army, WEAPON_SKILLS[ARCHER], location, UNIT_STATS[ARCHER])
{
	addItem(make_unique<Bow>());
}