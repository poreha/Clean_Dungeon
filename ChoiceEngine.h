#pragma once
#include <string> 
#include "Unit.h"
/*
	upon creation
		visualises specific choise variation
	.visualise
	.chooseFightAction
	.select gets user input, returns Button id
		Button id is used to invoke predetermined function
*/

struct button {
	int id = 0;
	const char* name;
	button* next = nullptr;
	button* prev = nullptr;
};

enum Choice { ACTION, TYPE, OTHER };

class ChoiceEngine
{

	
	int choiseAmount, ButtonID;

	void changeButtonIDup();
	void changeButtonIDdown();
	int getButtonID();
	button* createLinkedButtons(int , const char**);
public:
	ChoiceEngine(int );
	~ChoiceEngine();
	int select(button* );
	int select();
	void visualise();
	void chooseAction();
	int chooseType();
};

