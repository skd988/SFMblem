#pragma once

#include "Unit.h"

class Soldier : public Unit {
public:
	/*
		Constructor - initiates Unit with size, army and location,
		as well with Soldier's unique stats, weapon skills, texture and weapons.
	*/
	Soldier(float size, int army, Tile* location);
private:

};