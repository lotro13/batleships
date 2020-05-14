#include "pch.h"
#include "AI.h"
#include "console.h"
#include "captain.h"
#include "player.h"
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include <vector>

using namespace std;


AI::AI()
{
	srand(time(0));  // Initialize random number generator.
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			enemyField.setField(i, j, '1');

	for (int i = 0; i < 35; i++) {
		int x = (rand() % 10);
		int y = (rand() % 10);
		enemyField.setField(x, y, '2');
	}
}


void AI::placeShips(int vriant)
{
	vector<ship> tmp_fleet;
	int tmp_x_head, tmp_y_head, tmp_rotation;
	if (vriant == 1){ 
		bool ships_placed = false;
		vector<ship> tmp_fleet;
		while (!ships_placed) {
			//
			for (int i = 5; i > 1; i--) {
				bool repeat = false;
				do {
					tmp_x_head = rand() % 10;
					tmp_y_head = rand() % 10;
					tmp_rotation = rand() % 4 + 1;
					if ((!myField.canPlaceShip(tmp_x_head, tmp_y_head, tmp_rotation, i))
						|| ((tmp_x_head - (i - 1) < 0)
							|| (tmp_x_head + (i - 1) > 9)
							|| (tmp_y_head - (i - 1) < 0)
							|| (tmp_y_head + (i - 1) > 9))) {
						repeat = true;
					}
					else {
						repeat = false;
					}
				} while (repeat);
				if (!repeat) {
					ship* S = new ship;
					addShip(S, tmp_x_head, tmp_y_head, tmp_rotation, i);
					tmp_fleet.push_back(*S);
					addShip(tmp_x_head, tmp_y_head, tmp_rotation, i);
					myField.placeShip(tmp_x_head, tmp_y_head, tmp_rotation, i);
					break;
				}
			}
			//
		}
	}
	else if (vriant == 2) {
		int tmp = 1;
		field tmp_field = myField;
		for (int size = 4; size > 0; size--) {
			for (int qnt = 0; qnt < tmp; qnt++) {
				bool repeat = false;
				do {
					tmp_x_head = rand() % 10;
					tmp_y_head = rand() % 10;
					tmp_rotation = rand() % 4 + 1;
					if ((!myField.canPlaceShip(tmp_x_head, tmp_y_head, tmp_rotation, size))
						|| ((tmp_x_head - (size - 1) < 0)
							|| (tmp_x_head + (size - 1) > 9)
							|| (tmp_y_head - (size - 1) < 0)
							|| (tmp_y_head + (size - 1) > 9))) {
						repeat = true;
					}
					else {
						repeat = false;
					}
				} while (repeat);
				addShip(tmp_x_head, tmp_y_head, tmp_rotation, size);
				myField.placeShip(tmp_x_head, tmp_y_head, tmp_rotation, size);
			}
			tmp++;
		}
	}
}
vector<int> AI::makeShot() {
	/*Making choice*/
	int max_x;
	int max_y;
	int max = 0;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) {
			//cout << enemyField.getFieldAtPosition(i, j);
			if ((enemyField.getFieldAtPosition(i, j) != '3')
				&& (enemyField.getFieldAtPosition(i, j) != '4'))
				if ((int)(enemyField.getFieldAtPosition(i, j) - '0') > max) {
					max_x = i;
					max_y = j;
					max = (int)(enemyField.getFieldAtPosition(i, j) - '0');
				}
		}

	vector<int> tmp;
	tmp.push_back(max_x);
	tmp.push_back(max_y);
	return tmp;
}

	/*Marking
	0 - nothing
	1 - possible
	2 - probably
	3 - hit
	4 - destroy
	*/
void AI::analise(int x, int y, int result){
	if (result == 0) {
		enemyField.setField(x, y, '0');
	}
	else if (result == 1) {
		enemyField.setField(x, y, '3');
		if ((x > 0) && (y > 0)) {
			enemyField.setField(x - 1, y - 1, '0');

			if (enemyField.getFieldAtPosition(x - 1, y) == '1')
				enemyField.setField(x - 1, y, '2');
			if (enemyField.getFieldAtPosition(x, y - 1) == '1')
				enemyField.setField(x, y - 1, '2');
		}
		if ((x > 0) && (y < 9))
			enemyField.setField(x - 1, y + 1, '0');
		if ((x < 9) && (y > 0))
			enemyField.setField(x + 1, y - 1, '0');
		if ((x < 9) && (y < 9)) {
			enemyField.setField(x + 1, y + 1, '0');

			if (enemyField.getFieldAtPosition(x + 1, y) == '1')
				enemyField.setField(x + 1, y, '2');
			if (enemyField.getFieldAtPosition(x, y + 1) == '1')
				enemyField.setField(x, y + 1, '2');
		}
	}
	else if (result == 2) {
		enemyField.setField(x, y, '4');
		if ((x > 0) && (y > 0))
			enemyField.setField(x - 1, y - 1, '0');
		if ((x > 0) && (y < 9))
			enemyField.setField(x - 1, y + 1, '0');
		if ((x < 9) && (y > 0))
			enemyField.setField(x + 1, y - 1, '0');
		if ((x < 9) && (y < 9))
			enemyField.setField(x + 1, y + 1, '0');

		if (x > 0)
			if ((enemyField.getFieldAtPosition(x - 1, y) == '1')
				|| (enemyField.getFieldAtPosition(x - 1, y) == '2'))
				enemyField.setField(x - 1, y, '0');
		if (y > 0)
			if ((enemyField.getFieldAtPosition(x, y - 1) == '1')
				|| (enemyField.getFieldAtPosition(x, y - 1) == '2'))
				enemyField.setField(x, y - 1, '0');
		if (x < 9)
			if ((enemyField.getFieldAtPosition(x + 1, y) == '1')
				|| (enemyField.getFieldAtPosition(x + 1, y) == '2'))
				enemyField.setField(x + 1, y, '0');
		if (y < 9)
			if ((enemyField.getFieldAtPosition(x, y + 1) == '1')
				|| (enemyField.getFieldAtPosition(x, y + 1) == '2'))
				enemyField.setField(x, y + 1, '0');

	}
}