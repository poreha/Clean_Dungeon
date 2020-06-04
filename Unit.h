#pragma once
/*
	Is a parent-class for Monster and Player
	has set- methods for HP, DEF, DEX
*/

#include <iostream>
class Unit
{
	int unit_atc, unit_hp, unit_def;
	double unit_dex;
	const char* unit_name;

public:
	Unit();
	const char* getNAME();
	int getHP();
	int getDEF();
	double getDEX();

	void setName(const char*);
	void setATC(int attack);
	void setHP(int health);
	void setDEF(int defence); 
	void setDEX(double dexterity);
		

};


class Player : public Unit
{

	enum PlayerType { ADVENTURER, KNIGHT, ROGUE };

	void setTypeStats(Unit* , int );
	void setTypeStats(int );

public:
	Player();
	~Player();
};


/*
	upon creation
		sets base stats
	upon destruction
		prints famous last words
	.setMonsterName
		sets monster's name
	.setMonsterLevel
		sets monster's level
			int monsterLevel
				adds to the points pool, from which all the stats are drawn
	.getPointsPool //make it into Unit class
		gets monster's points pool
	.setPointsPool //make it into Unit class
		sets monster's points pool
*/
enum MonsterType { NEUTRAL, AGRESIVE, DEFENSIVE };

class Monster : public Unit
{
	const char* monsterName;
	int monsterLevel;
	int pointsPool;

public:
	Monster();
	~Monster();
	void setMonsterName(const char*);
	void setMonsterLevel(int);
	int getPointsPool();
	void setPointsPool();

};

