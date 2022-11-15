#include "Cavalier.h"
#include "Sword.h"
#include "Lance.h"

Cavalier::Cavalier(float size, int army, Tile* location) :
	Unit(UNIT_NAMES[CAVALIER], size, Textures::getUnitTexture(CAVALIER,army), army, WEAPON_SKILLS[CAVALIER], location, UNIT_STATS[CAVALIER])
{
	addItem(make_unique<Sword>());
	addItem(make_unique<Lance>());
}