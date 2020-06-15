#include "ChoiceEngine.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>

ChoiceEngine::ChoiceEngine(int choice_id)
{
	ChoiceEngine::answer = 0;
	button* menu = makeMenu(choice_id);

	//visualise(int,char*)

	answer = select(menu);

}

button* ChoiceEngine::makeMenu(int id)
{
	const char* heroTypes[3] = { "Adventurer" , "Knight", "Rogue" };
	const char* actionTypes[3] = { "Attack" , "Block", "Prepare" };

	button* tmp_menu = new button();
	ButtonList* linkedButtons = new ButtonList();

	if (id == ACTION)
	{
		tmp_menu = linkedButtons->makeButtonList(3, actionTypes);

	}
	else if (id == TYPE)
	{
		tmp_menu = linkedButtons->makeButtonList(3, heroTypes);
	}
	else if (id == OTHER)
	{
		//etc.
	}

	return tmp_menu;
}

int ChoiceEngine::select(button* choice)
{
	char input;
	while (1) {
		input = _getch();
		GetAsyncKeyState(input);
		if (input != 0x0D) {
			/*
				CHEATING!
				цикл перескакивает через один элемент
			*/
			if (GetAsyncKeyState(VK_UP)) {
				std::cout << choice->next->name << " is next ";
				choice = choice->next;
			}
			else if (GetAsyncKeyState(VK_DOWN)) {
				std::cout << choice->prev->name << " is prev: ";
				choice = choice->prev;
			}
			
		}
		else break;
	}
	std::cout << choice->id;
	return choice->id;
}

