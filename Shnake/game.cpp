#include "pch.h"
#include "game.h"
#include <vector>


game::game()
{
	Console = new console();
	gui = new GUI(*Console);
	Player = new player(Console, gui);
	ai = new AI();
}
void game::startGame() {
	Console->cls();
	gui->drawGameInterface(Player->getMyField(), Player->getEnemyField());
	ai->placeShips(2);
	Player->placeShips(2);
	int delta_comentator = 0;
	int head_coment_x = 55;
	int head_coment_y = 4;
	bool gameOver = false;
	int turn = 1;
	while (!gameOver) {
		Console->cls();
		gui->drawGameInterface(Player->getMyField(), Player->getEnemyField());
		//gui->drawGameInterface(ai->getMyField(), ai->getEnemyField(), 60, 0);
		if (turn == 1) {
			Player->makeShot(ai);
		}
		else if (turn == 2) {
			std::vector<int> tmp = ai->makeShot();
			int hit = Player->takeHit(tmp[0], tmp[1]);
			ai->analise(tmp[0], tmp[1], hit);
			Console->print("Computer shot at " + (char)((int)'0' + tmp[0]) + (char)((int)'A' + tmp[1]), head_coment_x, head_coment_y + delta_comentator);
			delta_comentator = (delta_comentator + 1) % 10;
		}

		turn = (turn % 2) + 1;
		gameOver = ((Player->getHP() == 0) || (ai->getHP() == 0));
	}
	Console->cls();
	if (Player->getHP() == 0) {
		cout << "You loose";
	}
	else if (ai->getHP() == 0) {
		cout << "You win";
	}
	cout << endl;
	system("pause");
	menu();
}
void game::menu() {
	Console->cls();
	gui->drawMenu();
	Console->change_console_view(15, 16);
	int choice;
	bool repeat = true;
	while (repeat) {
		Console->change_console_view(15, 16);
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			startGame();
			repeat = false;
			break;
		case 2:
			settings();
			repeat = false;
			break;
		case 3:
			system("exit");
			repeat = false;
			break;
		default:
			break;
		}
	}
}
void game::settings() {

}
game::~game()
{
	Console->cls();
}
