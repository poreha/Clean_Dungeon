#include "Button.h"

ButtonList::ButtonList()
{
	head = new button();
	head->id = 0;
	head->next = head->prev = head;
}

button* ButtonList::makeButtonList(int numButtons, const char** names)
{
	button* crawler;
	crawler = head;
	crawler->name = names[0];

	for (int i = 1; i < numButtons; i++)
	{
		button* link = new button();
		link->id = i;
		link->name = names[i];

		link->prev = crawler;
		crawler->next = link;

		crawler = link;
	}
	crawler->next = head;
	head->prev = crawler;

	return head;
}

ButtonList::~ButtonList()
{
	button* crawler;
	crawler = head;
	while (crawler->next != nullptr) {
		crawler->id = 0;
		crawler->name = "";
		crawler->prev = nullptr;
		crawler = crawler->next;
		crawler->prev->next = nullptr;
	}
}
