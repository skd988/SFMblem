#pragma once

#include "Unit.h"

class Cavalier : public Unit {
public:
	/*
		Constructor - initiates Unit with size, army and location,
		as well with Cavalier's unique stats, weapon skills, texture and weapons.
	*/
	Cavalier(float size, int army, Tile* location);

private:

};