#include "Knight.h"
#include "Lance.h"
Knight::Knight(float size, int army, Tile* location) :
	Unit(UNIT_NAMES[KNIGHT], size, Textures::getUnitTexture(KNIGHT, army), army, WEAPON_SKILLS[KNIGHT], location, UNIT_STATS[KNIGHT])
{
	addItem(make_unique<Lance>());
}