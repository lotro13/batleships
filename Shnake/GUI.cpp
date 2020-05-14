#include "pch.h"
#include "GUI.h"


GUI::GUI(console Console)
{
	this->Console = Console;
}

console GUI::getConsole() {
	return Console;
}

void GUI::drawMenu() {
	Console.cls();
	std::string menu[5] = {
		"BatleShips",
		"Menu",
		"1) Start Game",
		"2) Exit"
	};

	Console.print(menu[0], 30, 4);
	Console.print(menu[1], 33, 6);
	Console.print(menu[2], 28, 8);
	Console.print(menu[3], 31, 10);
}
void GUI::drawSettings() {
	Console.cls();
	Console.print("Nothing here yet", 33, 6);
}
void GUI::drawGameInterface() {
	Console.cls();
	string players_name = "Player";
	string AI_name = "AI";
	Console.print(players_name, 14, 4);
	Console.print(AI_name, 40, 4);
	drawField(battlefieldMe, 10, 7);
	drawField(battlefieldEnemy, 35, 7);
}
void GUI::drawGameInterface(field player, field computer) {
	string players_name = "Player";
	string AI_name = "AI";
	Console.print(players_name, 14, 4);
	Console.print(AI_name, 40, 4);
	drawField(player, 10, 7);
	drawField(computer, 35, 7);
}
void GUI::drawGameInterface(field player, field computer, int delta_x, int delta_y) {
	Console.cls();
	string players_name = "Player";
	string AI_name = "AI";
	Console.print(players_name, delta_x + 14, delta_y + 4);
	Console.print(AI_name, delta_x + 40, delta_y + 4);
	drawField(player, delta_x + 10, delta_y + 7);
	drawField(computer, delta_x + 35, delta_y + 7);
}
void GUI::drawField(field F, int x, int y) {
	char frame_x[10] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
	char frame_y[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

	for (int i = 0; i < 10; i++) {
		Console.print(frame_x[i], x + i * 2, y - 1);
		Console.print(frame_y[i], x - 2, y + i);
		Console.print(F, x, y);
	}
} 
void GUI::drawShip(vector<int> x, vector<int> y, vector<char> symbol) {
	for (int i = 0; i < x.size(); i++) {
		battlefieldMe.setField(x[i], y[i], symbol[i]);
	}
}
void GUI::setCursorToStartingPosition() {
	Console.change_console_view(0, 0);
}
void GUI::setFieldForMe(field F) {
	battlefieldMe = F;
}
void GUI::setFieldForEnemy(field F) {
	battlefieldEnemy = F;
}