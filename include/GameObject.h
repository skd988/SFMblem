#pragma once

#include <SFML/Graphics.hpp>

enum GameObjectNum { CURSOR };

class GameObject {
public:
	//Constructor - initiates m_sprite with texture, size and location.
	GameObject(const sf::Texture& texture, float size = -1, sf::Vector2f location = { 0, 0 });
	
	//Virtual Destructor - default.
	virtual ~GameObject() = default;

	//sets the position of m_sprite
	void setPosition(sf::Vector2f newLocation);

	//sets the color of m_sprite.
	void setColor(const sf::Color& color);

	//draws m_sprite on the window.
	void draw(sf::RenderWindow& window) const;

	//returns the position of m_sprite.
	sf::Vector2f getPosition() const;

	//returns the size of m_sprite - all the GameObjects are a square (height = length)
	float getSize() const;

private:
	//sets the size of the sprite.
	void setSize(float size);

	//the sprite - the graphic representation of the GameObject.
	sf::Sprite m_sprite;

};