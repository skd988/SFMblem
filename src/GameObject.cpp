#include "GameObject.h"
#include "Utilities.h"

GameObject::GameObject(const sf::Texture& texture, float size, sf::Vector2f location) :
	m_sprite(texture)
{
	if(size > 0)
		setSize(size);

	m_sprite.setPosition(location);
}

float GameObject::getSize() const
{
	return m_sprite.getGlobalBounds().height;
}

void GameObject::setSize(float size)
{
	setSpriteSize(m_sprite, sf::Vector2f(size, size));
}

void GameObject::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}

void GameObject::setPosition(sf::Vector2f newLocation)
{
	m_sprite.setPosition(newLocation);
}

sf::Vector2f GameObject::getPosition() const
{
	return m_sprite.getPosition();
}

void GameObject::setColor(const sf::Color& color)
{
	m_sprite.setColor(color);
}