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
ChoiceEngine::~ChoiceEngine()
{
	delete this;
}


int ChoiceEngine::chooseType()
{
	enum PlayerType { WARRIOR, TANK, ROGUE };
	const char** heroTypeNames = new const char*;
	*heroTypeNames = "Adventurer";
	*(++heroTypeNames) = "Knight";
	*(++heroTypeNames) = "Rogue";
	button linkedButtons = createLinkedButtons(3, heroTypeNames);

	return select(&linkedButtons);
}

int ChoiceEngine::select(button* choice)
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
			return choice->id;
		}
	}
}



//TEST THIS
button ChoiceEngine::createLinkedButtons(int numButtons, const char** names)
{
	if (numButtons > 0) {
		button start, * crawler;
		start.id = 0;
		start.name = names[0];

		start.next = &start;
		start.prev = &start;
		crawler = &start;

		for (int i = 1; i < numButtons; i++) {
			button btnNew;
			btnNew.id = i;
			btnNew.name = names[i];
			
			btnNew.prev = crawler;
			crawler->next = &btnNew;
			crawler = &btnNew;
		}
		crawler->next = &start;
		start.prev = crawler;

		return start;
	}
	else {
		std::cout << "Incorrect choice\n";
		button btnOK;
		btnOK.name = "OK";
		return btnOK;
	}
}


