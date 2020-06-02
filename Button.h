#pragma once
class Button
{
	int id;
	const char* name;
public:
	Button* next;
	Button* prev;

	Button();
	Button* makeListButtons(int , const char**);
	int getID();
	void setBTNname();

};

