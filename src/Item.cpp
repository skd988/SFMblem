#include "Item.h"

Item::Item(const sf::Texture& texture, string name) :
	GameObject(texture),
	m_name(name)
{
}
