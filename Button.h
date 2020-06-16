#pragma once

struct button {
	int id;
	const char* name;
	button* next;
	button* prev;
};

class ButtonList
{
	button* head;
	
public:
	ButtonList();
	~ButtonList();
	button* makeButtonList(int , const char**);
};

