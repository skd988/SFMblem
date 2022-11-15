#pragma once

#include "UnitAction.h"

const string WAIT_ACTION_NAME = "Wait";

class Level;

class WaitAction : public UnitAction {
public:
	//Constructor - initiates UnitAction with received unit.
	WaitAction(Unit* unit);

	//exectues action - does nothing.
	virtual void execute(Level& level);

private:

};