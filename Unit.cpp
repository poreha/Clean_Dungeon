#include "Unit.h"

Unit::Unit()
{
	unit_hp = 0;
	unit_def = 0;
	unit_dex = 0.0;
}

void Unit::setName(const char* new_name)
{
	unit_name = new_name;
}

void Unit::setATC(int attack) {
	Unit::unit_atc = attack;
}

void Unit::setHP(int health) {
	Unit::unit_hp = health;
}

void Unit::setDEF(int defence) {
	Unit::unit_def = defence;
}

void Unit::setDEX(double dexterity) {
	Unit::unit_dex = dexterity;
}

const char* Unit::getNAME()
{
	return unit_name;
}

int Unit::getHP(){
	return Unit::unit_hp;
}

int Unit::getDEF() {
	return Unit::unit_def;
}

double Unit::getDEX() {
	return Unit::unit_dex;
}
