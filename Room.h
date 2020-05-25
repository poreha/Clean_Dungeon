#pragma once
/*
	upon creation
		object randomises if there is a monster
	method .setPopulated
		gets hasMonster boolean
	method .isPopulated
		returns hasMonster boolean
	method .getAdress
		returns adress of the current Room
*/
#include "Unit.h"
class Room
{
	bool hasMonster;
	
	Monster* monster;
public:
	Room* nextRoom;

	Room();
	~Room();

	void setPopulation(bool);
	bool isPopulated();
	Room* getAdress();
	void setNext(Room*);
	void setMonster(Monster );
};

