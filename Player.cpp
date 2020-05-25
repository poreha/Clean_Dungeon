#include "Unit.h"
#include "ChoiceEngine.h"
#include <iostream>

Player::Player()
{	
	//const char* name;
	char* tmp_name = new char;
	std::cout << "What is thy name, Traveller?" << "\n";
	std::cin >> tmp_name;
	const char* name = static_cast<const char*>(tmp_name);
	this->setName(name);
	std::cout << "Choose your class:";
	ChoiceEngine HeroTypeChoice(TYPE);
	this->setTypeStats(HeroTypeChoice.chooseType());
	std::cout << this->getHP() << "\n";
}

Player::~Player()
{
	std::cout << "Our brave hero, " << this->getNAME() << ", has finished adventuring!\n";
	delete [] this;
}

void Player::setTypeStats(int hero_id)
{
	if (hero_id == WARRIOR) {
		this->setATC(5);
		this->setHP(5);
		this->setDEF(5);
		this->setDEX(0.3);
	}
	else if (hero_id == TANK) {
		this->setATC(3);
		this->setHP(6);
		this->setDEF(8);
		this->setDEX(0.1);
	}
	else if (hero_id == ROGUE) {
		this->setATC(7);
		this->setHP(4); 
		this->setDEF(3); 
		this->setDEF(3); 
		this->setDEX(0.5);
	}
}



