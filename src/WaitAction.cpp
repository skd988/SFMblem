#include "WaitAction.h"

WaitAction::WaitAction(Unit* unit) :
	UnitAction(WAIT_ACTION_NAME, unit)
{

}

void WaitAction::execute(Level& level)
{
	//do nothing, for now
}
