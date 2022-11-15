#include "Level.h"
#include "Utilities.h"
#include <fstream>

#include "Soldier.h"
#include "Archer.h"
#include "Knight.h"
#include "Cavalier.h"
#include "Bishop.h"
#include "Mage.h"

Level::Level(int level_num, sf::RenderWindow& window) :
	m_level_num(level_num),
	m_background(Textures::getLevelBackground(m_level_num)),
	m_window(adaptWindow(window)),
	m_board(openLevelFile(level_num), window.getSize()),
	m_chosen(nullptr),
	m_pointed(nullptr),
	m_cursor(m_board.getTile({ m_board.getSize().x / 2, m_board.getSize().y / 2 }), m_board.getTileSize()),
	m_unit_data_block(sf::Vector2f(window.getSize()) - sf::Vector2f(DATA_BLOCK_LENGTH, UNIT_DATA_BLOCK_HEIGHT), DATA_BLOCK_LENGTH)
{
	string army;
	int numOfSoldiers;

	m_levels_file.get();
	
	for (int k = 0; k < NUM_OF_ARMYS; ++k) 
	{
		m_armys.emplace_back();
		m_levels_file >> numOfSoldiers;
		initArmy(numOfSoldiers, k);
	}
	m_levels_file.close();
}

ifstream& Level::openLevelFile(int level_num)
{
	m_levels_file.open(LEVEL_NAMES[level_num]);
	if (!m_levels_file.is_open())
		exit(EXIT_FAILURE);//file error

	return m_levels_file;
}

void Level::initArmy(int numOfSoldiers, int armyNum)
{
	vector<unique_ptr<Unit>>& army = m_armys[armyNum];
	char type;
	int x;
	int y;
	for (int i = 0; i < numOfSoldiers; ++i) {
		m_levels_file >> type;
		m_levels_file >> x;
		m_levels_file >> y;
		if (type == UNIT_CHAR[SOLDIER])
			army.emplace_back(make_unique<Soldier>(m_board.getTileSize(), armyNum, m_board.getTile(sf::Vector2i(x, y))));
		else if (type == UNIT_CHAR[ARCHER])
			army.emplace_back(make_unique<Archer>(m_board.getTileSize(), armyNum, m_board.getTile(sf::Vector2i(x, y))));
		else if(type == UNIT_CHAR[CAVALIER])
			army.emplace_back(make_unique<Cavalier>(m_board.getTileSize(), armyNum, m_board.getTile(sf::Vector2i(x, y))));
		else if(type == UNIT_CHAR[KNIGHT])
			army.emplace_back(make_unique<Knight>(m_board.getTileSize(), armyNum, m_board.getTile(sf::Vector2i(x, y))));
		else if(type == UNIT_CHAR[BISHOP])
			army.emplace_back(make_unique<Bishop>(m_board.getTileSize(), armyNum, m_board.getTile(sf::Vector2i(x, y))));
		else if(type == UNIT_CHAR[MAGE])
			army.emplace_back(make_unique<Mage>(m_board.getTileSize(), armyNum, m_board.getTile(sf::Vector2i(x, y))));
	}
}

int Level::run()
{
	int outcome = -1;
	getBackgroundMusic().play();
	while (outcome == -1) {
		for (int army = 0; army < NUM_OF_ARMYS && outcome == -1; ++army)
		{
			if ((outcome = playTurn(army)) != -1)
				break;
			for (auto& unit : m_armys[army])
				unit->wake();
		}
	}
	getBackgroundMusic().stop();
	return outcome;
}

int Level::playTurn(int army)
{
	m_cursor.changeArmy(army);
	int moves = 0;
	sf::Event event;

	while (moves < m_armys[army].size())
	{
		m_pointed = m_cursor.getTile()->getUnit();
		draw();
		m_window.display();

		if (m_window.waitEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				exitProgram(m_window);

			case sf::Event::KeyPressed:

				if (event.key.code == sf::Keyboard::Left)
					m_cursor.move(LEFT);

				else if (event.key.code == sf::Keyboard::Right)
					m_cursor.move(RIGHT);

				else if (event.key.code == sf::Keyboard::Down)
					m_cursor.move(DOWN);

				else if (event.key.code == sf::Keyboard::Up)
					m_cursor.move(UP);

				else if (event.key.code == sf::Keyboard::Z) {
					if (m_chosen == nullptr) {
						m_chosen = m_pointed;

						if (m_chosen != nullptr) {
							if (m_chosen->getArmy() != army || m_chosen->isIdle())
								m_chosen = nullptr;
							else
								m_chosen->updateTileRange();
						}
					}
					else
					{
						Tile* lastLoc = m_chosen->getTile();
						if (!m_chosen->move(m_cursor.getTile()))
							continue;
						CommandMenu menu = m_chosen->getCommandMenu(m_board, { float(m_window.getSize().x - DATA_BLOCK_LENGTH), 0 });
						draw();
						if (menu.run(*this)) {
							draw();
							menu.choose(*this);
							m_chosen->sleep();
							++moves;
						}
						else {
							m_chosen->move(lastLoc);
						}
						m_chosen = nullptr;
					}
				}
				else if (event.key.code == sf::Keyboard::X) {
					m_chosen = nullptr;
				}
			}
		}
		int whichArmy = isArmyDead();
		if (whichArmy != -1) {
			return whichArmy;
		}
	}
	return -1;
}

//int Level::run()
//{
//	getBackgroundMusic().play();
//	auto event = sf::Event{};
//	while (true) {
//		for (int army = 0; army < NUM_OF_ARMYS; ++army) 
//		{
//			m_cursor.changeArmy(army);
//			int moves = 0;
//			
//			while(moves < m_armys[army].size())
//			{
//				m_pointed = m_cursor.getTile()->getUnit();
//				draw();
//				m_window.display();
//
//				if (m_window.waitEvent(event)) {
//					switch (event.type) {
//					case sf::Event::Closed:
//						exitProgram(m_window);
//
//					case sf::Event::KeyPressed:
//
//						if (event.key.code == sf::Keyboard::Left)
//							m_cursor.move(LEFT);
//
//						else if (event.key.code == sf::Keyboard::Right)
//							m_cursor.move(RIGHT);
//
//						else if (event.key.code == sf::Keyboard::Down)
//							m_cursor.move(DOWN);
//
//						else if (event.key.code == sf::Keyboard::Up)
//							m_cursor.move(UP);
//
//						else if (event.key.code == sf::Keyboard::Z) {
//							if (m_chosen == nullptr) {
//								m_chosen = m_pointed;
//							
//								if (m_chosen != nullptr) {
//									if (m_chosen->getArmy() != army || m_chosen->isIdle()) 
//										m_chosen = nullptr;
//									else {
//										m_chosen->updateTileRange();
//
//										
//									}
//								}
//							}
//							else 
//							{
//								Tile* lastLoc = m_chosen->getTile();
//								if (!m_chosen->move(m_cursor.getTile()))
//									continue;
//								CommandMenu menu = m_chosen->getCommandMenu(m_board, { float(m_window.getSize().x - DATA_BLOCK_LENGTH), 0 });
//								draw();
//								if (menu.run(*this)) {
//									draw();
//									menu.choose(*this);
//									m_chosen->sleep();
//									++moves;
//								}
//								else {
//									m_chosen->move(lastLoc);
//								}
//								m_chosen = nullptr;
//							}
//						}
//						else if (event.key.code == sf::Keyboard::X) {
//							m_chosen = nullptr;
//						}
//					}
//				}
//				int whichArmy = isArmyDead();
//				if (whichArmy != -1) {
//					getBackgroundMusic().stop();
//					return whichArmy;
//				}
//			}
//			for (auto& unit : m_armys[army])
//				unit->wake();
//		}
//
//	}
//}

int Level::isArmyDead() const
{
	for (int army = 0; army < NUM_OF_ARMYS; ++army)
		if (m_armys[army].size() == 0)
			return (army + 1) % NUM_OF_ARMYS;

	return -1;
}

void Level::deleteUnit(const Unit* unit)
{
	auto& army = m_armys[unit->getArmy()];
	for (auto it = army.begin(); it < army.end(); ++it){
		if (it->get() == unit) {
			it->get()->die();
			army.erase(it);
			break;
		}
	}
}

void Level::draw()
{
	m_window.clear(DATA_BLOCK_COLOR);
	m_window.draw(m_background);
	if (m_chosen) {
		m_chosen->drawRange(m_window);
	}
	for (auto& armyV : m_armys)
		for (auto& unit : armyV)
			unit->draw(m_window);

	if (m_pointed) {
		m_unit_data_block.update(m_pointed);
		m_unit_data_block.draw(m_window);
	}
	m_cursor.draw(m_window);
}

sf::RenderWindow& Level::adaptWindow(sf::RenderWindow& window) 
{
	window.setSize({ unsigned int(m_background.getGlobalBounds().width) + DATA_BLOCK_LENGTH, unsigned int(m_background.getGlobalBounds().height) });
	window.setView(sf::View(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y)));
	return window;
}

sf::RenderWindow& Level::getWindow() const
{
	return m_window;
}
