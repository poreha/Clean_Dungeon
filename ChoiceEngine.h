#pragma once

#include "Button.h"
/*
	upon creation
		visualises specific choise variation
	.visualise
	.chooseFightAction
	.select gets user input, returns Button id
		Button id is used to invoke predetermined function
*/


enum Choice { ACTION, TYPE, OTHER };

class ChoiceEngine
{
	
	button* menu;
	button* makeMenu(int);
public:
	int answer;

	ChoiceEngine(int );

	int select(button* );

	void visualise();
	button* chooseAction();
	button* chooseType();

};

