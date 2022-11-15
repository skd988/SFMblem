#pragma once
#include <SFML/Graphics.hpp>
#include "Command.h"
#include "Unit.h"
#include <string>

using std::string;
class Level;

class UnitAction : public Command {
public:
	/*
		Constructor - initiates Command with name, 
		and the unit that the action is referring to.
	*/
	UnitAction(string name, Unit* unit);

	//returns the unit the action is referring to.
	Unit* getUnit() const;

private:
	Unit* m_unit;

};