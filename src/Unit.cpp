#include "Unit.h"
#include "WaitAction.h"
#include "AttackAction.h"
#include "CommandMenu.h"
#include "Weapon.h"
#include "Board.h"
#include "Utilities.h"

Unit::Unit(string classOfUnit, float size, const sf::Texture& texture, int army, const array<bool, NUM_OF_WEAPONS>& weapons_skill, Tile* location, UnitStats stats) :
	GameObject(texture, size, sf::Vector2f(location->getLocation()) * size),
	m_idle(false),
	m_stats(stats),
	m_army(army),
	m_weapons_skill(weapons_skill),
	m_class(classOfUnit),
	m_location(location),
	m_currHp(stats.m_maxHp),
	m_weapon_equipped(nullptr),
	m_range_rect({ getSize(), getSize() })
{
	m_healthChange.setFillColor(sf::Color::Red);
	m_healthChange.setFont(getFont());
	m_healthChange.setCharacterSize(CHANGE_HEALTH_FONT_SIZE);
	m_healthChange.setStyle(sf::Text::Bold);

	m_range_rect.setFillColor(RANGE_COLOR);

	m_location->setUnit(this);
}

bool Unit::move(Tile* destination)
{
	if (destination == m_location)
		return true;

	if (m_tile_range.find(destination) == m_tile_range.end() || destination->getUnit() != nullptr)
		return false;

	m_location->setUnit(nullptr);
	m_location = destination;
	setPosition(sf::Vector2f(destination->getLocation()) * getSize());
	m_location->setUnit(this);
	return true;
}

CommandMenu Unit::getCommandMenu(const Board& board, sf::Vector2f location)
{
	CommandMenu CommandMenu(location);
	CommandMenu.add(make_unique<WaitAction>(this));
	vector<Unit*> enemiesInRange(getEnemiesInRange(board));
	if (enemiesInRange.size() > 0)
		CommandMenu.add(make_unique<AttackAction>(this, enemiesInRange));
	
	return CommandMenu;
}

bool Unit::isDead() const
{
	return m_currHp <= 0;
}


void Unit::die()
{
	m_location->setUnit(nullptr);
}

void Unit::printDamage(sf::RenderWindow& window, int damage)
{
	if (damage == CANT_DAMAGE)
		return;
	if (damage == MISS)
		m_healthChange.setString("Miss!");
	else
		m_healthChange.setString(std::to_string(-damage));

	m_healthChange.setPosition(getPosition() + sf::Vector2f(0, float(-CHANGE_HEALTH_FONT_SIZE*1.2)));

    window.draw(m_healthChange);
	window.display();
	sf::sleep(sf::milliseconds(1000));
}

void Unit::changeHealth(int offset)
{
	m_currHp += offset;

	if (m_currHp >= m_stats.m_maxHp)
		m_currHp = m_stats.m_maxHp;
}

void Unit::EncounterEnemy(sf::RenderWindow& window, Unit* enemy)
{
	enemy->printDamage(window, Damage(enemy));
	if(!enemy->isDead())
		printDamage(window, enemy->Damage(this));
	
}

int Unit::Damage(Unit* enemy)
{
	if (m_weapon_equipped == nullptr)
		return CANT_DAMAGE;

	UnitStats enemyStats = enemy->m_stats;
	WeaponStats weaponStats = m_weapon_equipped->getStats();
	
	int distance = m_location->getDistance(enemy->m_location);

	if (!(weaponStats.m_minRange <= distance && distance <= weaponStats.m_maxRange))
		return CANT_DAMAGE;

	int hitChance = m_stats.m_skill + weaponStats.m_hitChance - enemyStats.m_speed;

	if (randRange(0, 100) <= hitChance){
		int damage = m_stats.m_attack + weaponStats.m_damage - enemyStats.m_defense;
		enemy->changeHealth(-damage);
		return damage;
	}
	return MISS;
}

void Unit::drawRange(sf::RenderWindow& window) const
{
	sf::RectangleShape rect(m_range_rect);
	for (auto& i : m_tile_range){
		rect.setPosition(sf::Vector2f(i.first->getLocation()) * getSize());
		window.draw(rect);
	}
}

bool Unit::isIdle() const
{
	return m_idle;
}

void Unit::wake()
{
	setColor(sf::Color::White);
	m_idle = false;
}

void Unit::sleep()
{
	setColor(SLEEP_COLOR);
	m_idle = true;
}

Tile* Unit::getTile() const
{
	return m_location;
}

int Unit::getArmy() const
{
	return m_army;
}

string Unit::getClass() const
{
	return m_class;
}

UnitStats Unit::getStats() const
{
	return m_stats;
}

int Unit::getCurrHp() const
{
	return m_currHp;
}

vector<Unit*> Unit::getEnemiesInRange(const Board& board)
{
	vector<Unit*> enemy_range;
	sf::Vector2i unitLocation = m_location->getLocation();
	sf::Vector2i location;
	Unit* unit;

	if (m_weapon_equipped != nullptr) {
		WeaponStats stats = m_weapon_equipped->getStats();
		for (int range = stats.m_minRange; range <= stats.m_maxRange; ++range) {
			for (int x = -range; x <= range; ++x) {
				location.x = unitLocation.x + x;
				int remain = range - abs(location.x - unitLocation.x);
				location.y = unitLocation.y + remain;
				tryAddEnemy(enemy_range, board.getTile(location));

				if (remain > 0) {
					location.y = unitLocation.y - remain;
					tryAddEnemy(enemy_range, board.getTile(location));
				}
			}
		}
	}

	return enemy_range;
}

void Unit::tryAddEnemy(vector<Unit*>& enemy_range, Tile* tile)
{
	if (tile != nullptr) {
		Unit* unit = tile->getUnit();
		if (unit != nullptr && unit->getArmy() != getArmy()) {
			enemy_range.emplace_back(unit);
		}
	}
}

void Unit::updateTileRange()
{
	m_tile_range.clear();
	updateTileRangeRec(m_location, m_location, m_stats.m_movement);
}

void Unit::updateTileRangeRec(Tile* currentTile, Tile* destTile, int movement)
{
	if (currentTile == nullptr || destTile == nullptr)//tiles arent valid (usually destTile, if out of bounds)
		return;

	if (auto dest = m_tile_range.find(destTile); dest != m_tile_range.end()) {//tile is already in tile range.
		if (dest->second.second >= movement)
			return;
		else
			m_tile_range.erase(dest);
	}
	
	const Unit* unit = destTile->getUnit();

	if (unit != nullptr && unit->getArmy() != m_army)
		return;

	if (currentTile != destTile){
		int terrainLevel = destTile->getTerrainLevel();
		if(terrainLevel == -1)
			return;

		movement -= terrainLevel;
		if (movement < 0)
			return;

	}

	
	m_tile_range.insert({ destTile, {currentTile, movement} });

	for (int dir = 0; dir < NUM_OF_DIRECTIONS; ++dir)
		updateTileRangeRec(destTile, destTile->getNeighbor(Direction(dir)), movement);

}

void Unit::addItem(unique_ptr<Item> item)
{
	unique_ptr<Item>& last = m_items.emplace_back(std::move(item));
	if (m_weapon_equipped == nullptr)
		m_weapon_equipped = dynamic_cast<Weapon*>(last.get());
}


