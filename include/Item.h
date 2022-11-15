#pragma once

#include "GameObject.h"
#include <string>

using std::string;

class Item : public GameObject{
public:
	/*
		Constructor - initiates GameObject with texture,
		and the name of the item.
	*/
	Item(const sf::Texture& texture, string name);

private:
	//name of the item.
	string m_name;

};