#include "Mage.h"
#include "SpellBook.h"

Mage::Mage(float size, int army, Tile* location) :
	Unit(UNIT_NAMES[MAGE], size, Textures::getUnitTexture(MAGE,army), army, WEAPON_SKILLS[MAGE], location, UNIT_STATS[MAGE])
{
	addItem(make_unique<SpellBook>());
}