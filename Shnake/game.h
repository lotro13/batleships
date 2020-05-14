#pragma once
#include "captain.h"
#include "GUI.h"
#include "console.h"
#include "player.h"
#include "AI.h"
class game
{
private:
	bool game_started = false;
	console* Console;
	GUI* gui;
	player* Player;
	AI* ai;
public:
	game();
	void menu();
	void startGame();
	void settings();
	~game();
};

