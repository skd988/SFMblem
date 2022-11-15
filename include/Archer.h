#pragma once

#include "Unit.h"

class Archer : public Unit {
public:
	/*
		Constructor - initiates Unit with size, army and location,
		as well with Archer's unique stats, weapon skills, texture and weapons.
	*/
	Archer(float size, int army, Tile* location);

private:

};