#pragma once
#include "field.h"
#include <string>
class console
{
public:
	console();
	~console();
	//void print(char** battlefield, int width, int heigth);
	void print(char, int, int);
	void print(std::string, int, int);
	void print(field, int, int);
	void cls();
	void change_console_view(int, int);
	/*friend void drawMenu(console &Console);
	friend void drawGameInterface(console &Console);*/
};

