#include "ChoiceEngine.h"
#include <iostream>

ChoiceEngine::ChoiceEngine(int choice_id)
{
	ChoiceEngine::ButtonID = 0;
	
	if (choice_id == ACTION)
	{
		//chooseAction()
		
	}
	else if (choice_id == TYPE)
	{
		chooseType();
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

//
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
//

void ChoiceEngine::changeButtonIDup()
{
	if ((ButtonID + 1) > choiseAmount) {
		ButtonID = 0;
	}
	else {
		ButtonID = ButtonID + 1;
	}
}

void ChoiceEngine::changeButtonIDdown()
{
	if ((ButtonID - 1) < 0) {
		ButtonID = choiseAmount;
	}
	else {
		ButtonID = ButtonID - 1;
	}
}


int ChoiceEngine::getButtonID()
{
	return ButtonID;
}

//TEST THIS
button* ChoiceEngine::createLinkedButtons(int numButtons, const char** names)
{
	if (numButtons > 1) {
		button start, * top;
		/*start = new button;
		start->id = 0;
		start->name = names[0];
		start->next = start;
		start->prev = start;
		*/
		start.id = 0;
		start.name = names[0];
		start.next = &start;
		start.prev = &start;
		top = &start;
		for (int i = 1; i < numButtons; i++) {
			button new_btn;// create new button
			new_btn.id = i;
			new_btn.name = names[i];
			new_btn.next = &start; // loop forward to the start
			new_btn.prev = top; // go to previous top
			start.prev = &new_btn; // loop from the start back
			top = &new_btn; // change current pointer to the latest addition
		}

		return &start;
	}
	else {
		std::cout << "Incorrect choice\n";
		return nullptr;
	}
}

int ChoiceEngine::chooseType()
{
	enum PlayerType { WARRIOR, TANK, ROGUE };
	const char** heroTypeNames = new const char*;
	heroTypeNames[0] = "Adventurer";
	heroTypeNames[1] = "Knight";
	heroTypeNames[2] = "Rogue";
	button* linkedButtons = createLinkedButtons(3, heroTypeNames);

	return select(linkedButtons);
}
