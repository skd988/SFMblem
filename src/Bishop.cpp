#include "Bishop.h"
#include "Stuff.h"

Bishop::Bishop(float size, int army, Tile* location) :
	Unit(UNIT_NAMES[BISHOP], size, Textures::getUnitTexture(BISHOP,army), army, WEAPON_SKILLS[BISHOP], location, UNIT_STATS[BISHOP])
{
	addItem(make_unique<Stuff>());
}