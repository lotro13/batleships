#pragma once
#include "captain.h"
#include "console.h"
#include "GUI.h"
#include "AI.h"

using namespace std;

class player : public captain
{
private:
	console* Console;
	GUI* gui;
public:
	player(console*, GUI*);
	void placeShips(int);
	void makeShot(AI*);
};

