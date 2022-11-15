#include "Weapon.h"

Weapon::Weapon(const sf::Texture& texture, WeaponStats stats, string name):
	Item(texture, name),
	m_stats(stats)
{

}

WeaponStats Weapon::getStats() const
{
	return m_stats;
}