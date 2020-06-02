#include "Button.h"

Button::Button()
{
	id = 0;
	next = nullptr;
	prev = nullptr;
	name = "";
}

Button* Button::makeListButtons(int numButtons, const char** names)
{
	if (numButtons > 0) {
		Button* start, * crawler;
		start = new Button();
		start->id = 0;
		start->name = names[0];

		start->next = start;
		start->prev = start;
		crawler = start;

		for (int i = 1; i < numButtons; i++) {
			Button* btnNew = new Button();
			btnNew->id = i;
			btnNew->name = names[i];

			btnNew->prev = crawler;
			crawler->next = btnNew;

			crawler = btnNew;
		}
		crawler->next = start;
		start->prev = crawler;

		return start;
	}
	else {
		Button* btnOK = new Button();
		btnOK->name = "OK";
		return btnOK;
	}
}

int Button::getID()
{
	return this->id;
}