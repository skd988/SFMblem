#pragma once

#include "Unit.h"

class Mage : public Unit {
public:
	/*
		Constructor - initiates Unit with size, army and location,
		as well with Mage's unique stats, weapon skills, texture and weapons.
	*/
	Mage(float size, int army, Tile* location);

private:

};