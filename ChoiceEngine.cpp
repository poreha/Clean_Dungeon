#include "ChoiceEngine.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>

ChoiceEngine::ChoiceEngine(int choice_id)
{
	answer = 0;
	button* menu = decide(choice_id);

	//visualise(int,char*)

	answer = select(menu);

}

button* ChoiceEngine::decide(int id)
{
	button* tmp_menu = new button();
	if (id == ACTION)
	{
		//chooseAction()

	}
	else if (id == TYPE)
	{
		tmp_menu = chooseType();
	}
	else if (id == OTHER)
	{
		//etc.
	}

	return tmp_menu;
}

button* ChoiceEngine::chooseType()
{
	const char* heroTypes[3] = { "Adventurer" , "Knight", "Rogue" };

	ButtonList* linkedButtons = new ButtonList();
	button* typeMenu = linkedButtons->makeButtonList(3, heroTypes);

	return typeMenu;
}


int ChoiceEngine::select(button* choice)
{
	char input;
	while (1) {
		input = _getch();
		if (input != 0x0D) {
			if (GetKeyState(VK_DOWN)) {
				std::cout << choice->next->name << " is next ";
				choice = choice->next;
			}
			else if (GetKeyState(VK_UP)) {
				std::cout << choice->prev->name << " is prev: ";
				choice = choice->prev;
			}
			
		}
		else break;
	}
	std::cout << choice->id;
	return choice->id;
}

