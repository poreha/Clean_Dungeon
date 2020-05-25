#include "DungeonMaster.h"
#include <stdlib.h>

DungeonMaster::DungeonMaster(int level)
{
	DungeonMaster::dungeonLevel = level;
	startingRoom.setNext(&finalRoom);
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

Room* DungeonMaster::createLinkedRooms(int numRooms)
{
	Room* dungeon = new Room;
	startingRoom.setPopulation(false);
	finalRoom.setPopulation(false);
	dungeon[0] = startingRoom;
	for (int i = 1; i < numRooms; i++) {
		dungeon[i] = *createRoom();
		dungeon[i - 1].setNext(&dungeon[i]);
	}
	dungeon[numRooms].setNext(&finalRoom);
	
	return dungeon;
}

void DungeonMaster::populate(Room* tempRoom, Monster tempMonster)
{
	if (tempRoom->isPopulated())
	{
		tempRoom->setMonster(tempMonster);
	}
}