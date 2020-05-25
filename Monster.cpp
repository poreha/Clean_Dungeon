#include "Unit.h"

Monster::Monster()
{
	
	Monster::monsterLevel = 1;
	Monster::monsterName = "Nameless";
	Monster::pointsPool = 10;
	
	int type_id = NEUTRAL;
}

Monster::~Monster()
{
	std::cout << this->monsterName << " is defeated\n";
	delete this;
}

void Monster::setMonsterLevel(int Level)
{
	monsterLevel = Level;
}

void Monster::setMonsterName(const char* name)
{
	monsterName = name;
}