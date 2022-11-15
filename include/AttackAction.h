#pragma once

#include <vector>

#include "UnitAction.h"
#include "EnemiesToAttackMenu.h"
#include "Utilities.h"

using std::vector;

class Level;

const string ATTACK_ACTION_NAME = "Attack";

class AttackAction : public UnitAction {
public:
	AttackAction(Unit* unit, vector<Unit*>& enemies);
	virtual void execute(Level& level);

private:
	EnemiesToAttackMenu m_enemies_menu;

};