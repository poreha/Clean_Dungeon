#include "Room.h"


Room::Room() 
{
	nextRoom = nullptr;
	hasMonster = false;
}

Room::~Room() 
{
	delete this;
}

void Room::setPopulation(bool populus)
{
	hasMonster = populus;
}

bool Room::isPopulated()
{
	return hasMonster;
}

Room* Room::getAdress()
{
	return this;
}

void Room::setNext(Room* nextAdress)
{
	nextRoom = nextAdress;
}

void Room::setMonster(Monster tempMonster)
{
	*monster = tempMonster;
}