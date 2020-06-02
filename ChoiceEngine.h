#pragma once
#include <string> 
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

public:
	ChoiceEngine(int );

	int select(Button* );
	int select();
	void visualise();
	void chooseAction();
	int chooseType();
};

