#include "AttackAction.h"
#include "Level.h"
#include <SFML/Audio.hpp>

AttackAction::AttackAction (Unit* unit, vector<Unit*>& enemies):
	UnitAction(ATTACK_ACTION_NAME, unit),
	m_enemies_menu(enemies)
{

}

void AttackAction::execute(Level& level)
{
	getBackgroundMusic().pause();
	getBattleMusic().play();
	m_enemies_menu.run(level);
	Unit* enemyToAttack = m_enemies_menu.getChosenEnemy();
	Unit* unit = getUnit();
	unit->EncounterEnemy(level.getWindow(), enemyToAttack);

	if (unit->isDead())
		level.deleteUnit(unit);
	if (enemyToAttack->isDead())
		level.deleteUnit(enemyToAttack);
	getBattleMusic().pause();
	getBackgroundMusic().play();
}


