#include "UnitAction.h"

UnitAction::UnitAction(string name, Unit* unit):
	Command(name),
	m_unit(unit)
{

}

Unit* UnitAction::getUnit() const
{
	return m_unit;
}
