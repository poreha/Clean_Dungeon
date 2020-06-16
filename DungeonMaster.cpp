#include "DungeonMaster.h"
#include <stdlib.h>

DungeonMaster::DungeonMaster(int level)
{
	DungeonMaster::dungeonLevel = level;
	startingRoom->setNext(finalRoom);
}

Room* DungeonMaster::createLinkedRooms(int numRooms)
{
	Room* crawler;
	startingRoom->setPopulation(false);
	finalRoom->setPopulation(false);

	crawler = startingRoom;

	for (int i = 1; i < numRooms; i++)
	{
		Room* link = createRoom();
		crawler->setNext(link);
		crawler = link;
	}
	crawler->setNext(finalRoom);
	return startingRoom;
}

Room* DungeonMaster::createRoom()
{
	Room* newRoom = new Room;
	int setProbability = rand() % 10;
	if (setProbability <= (5 - DungeonMaster::dungeonLevel))
	{
		newRoom->setPopulation(false);
	}
	else
	{
		newRoom->setPopulation(true);
	}
	return newRoom;
}


void DungeonMaster::populate(Room* tempRoom, Monster tempMonster)
{
	if (tempRoom->isPopulated())
	{
		tempRoom->setMonster(tempMonster);
	}
}