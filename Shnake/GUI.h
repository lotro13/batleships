#pragma once
#include "console.h"
#include "field.h"
#include <string>

using namespace std;
class GUI
{
private:
	console Console;
	field battlefieldMe;
	field battlefieldEnemy;
public:
	GUI(console);
	console getConsole();
	void drawMenu();
	void drawSettings();
	void drawGameInterface();
	void drawGameInterface(field, field);
	void drawGameInterface(field, field, int, int);
	void drawField(field, int, int);
	void drawShip(vector<int>, vector<int>, vector<char>);
	void setCursorToStartingPosition();
	void setFieldForMe(field);
	void setFieldForEnemy(field);
};