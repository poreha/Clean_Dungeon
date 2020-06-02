#include "ChoiceEngine.h"
#include <iostream>

ChoiceEngine::ChoiceEngine(int choice_id)
{
	
	if (choice_id == ACTION)
	{
		//chooseAction()
		
	}
	else if (choice_id == TYPE)
	{
		this->chooseType();
	}
	else if (choice_id == OTHER)
	{
		//etc.
	}
	//visualise(int,char*)
	//select(int)

}



int ChoiceEngine::chooseType()
{
	enum PlayerType { WARRIOR, TANK, ROGUE };
	const char* heroTypeNames[3] = { "Adventurer" , "Knight", "Rogue" };

	Button* linkedButtons = new Button();
	linkedButtons->makeListButtons(3, heroTypeNames);

	return select(linkedButtons);
}

int ChoiceEngine::select(Button* choice)
{
	char input;
	while (1) {
		std::cin >> input;
		if (input == '1')//understand how to work with virt keyboards
		{
			choice = choice->next;
		}
		else if (input == '2')
		{
			choice = choice->prev;
		}
		else if (input == '3')
		{
			return choice->getID();
		}
	}
}


