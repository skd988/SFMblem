#pragma once

#include "Unit.h"

class Bishop : public Unit {
public:
	/*
		Constructor - initiates Unit with size, army and location,
		as well with Bishop's unique stats, weapon skills, texture and weapons.
	*/
	Bishop(float size, int army, Tile* location);

private:

};