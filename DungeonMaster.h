#pragma once
/*
	upon creation
		makes starting and final Rooms of the dungeon,
		gets dungeon's level
			~make diffitulty exponential
	method .createRoom
		cheates a Room and sets hasMonster boolean, according to level
	method .link
		gets number of rooms and creates a linked array of Rooms
	method .populate
		gets that array of Rooms and populates them with monsters, 
		checking each Room's hasMonsters boolean
	method .pass 
		checks if player has passed the room
*/

#include "Room.h"

class DungeonMaster
{
	int dungeonLevel;
	Room* startingRoom;
	Room* finalRoom;
public:
	DungeonMaster(int );
	Room* createRoom();
	Room* createLinkedRooms(int );
	void populate(Room*, Monster );
};

