#include "pch.h"
#include "player.h"
#include "preview.h"
#include <conio.h>

constexpr auto KEY_UP = 72;
constexpr auto KEY_DOWN = 80;
constexpr auto KEY_LEFT = 75;
constexpr auto KEY_RIGHT = 77;
constexpr auto KEY_ROTATE = 114;
constexpr auto KEY_END = 101;

player::player(console* C, GUI* G) {
	Console = C;
	gui = G;
	Console->change_console_view(10, 1);
	cout << "Use arrow keys to move ship, e - to place ship, r - to rotate ship";
};
void player::placeShips(int vriant) {
	preview PREVIEW(Console);
	bool ships_placed = false;
	int c = 0;
	int tmp_x = 4;
	int tmp_y = 4;
	int rotation = 1;

	if (vriant == 1) {
		int size = 5;
		field tmp_field = myField;
		while (!ships_placed) {
			PREVIEW.drawShip(tmp_x, tmp_y, size, rotation, myField);

			c = 0;
			switch ((c = _getch())) {
			case KEY_UP:
				if (((rotation == 1) && (tmp_x - (size - 1) > 0))
					|| (((rotation == 2) || (rotation == 3) || (rotation == 4)) && (tmp_x > 0)))
					tmp_x--;
				break;
			case KEY_DOWN:
				if (((rotation == 3) && (tmp_x + (size - 1) < 9))
					|| (((rotation == 1) || (rotation == 2) || (rotation == 4)) && (tmp_x < 9)))
					tmp_x++;
				break;
			case KEY_LEFT:
				if (((rotation == 4) && (tmp_y - (size - 1) > 0))
					|| (((rotation == 1) || (rotation == 2) || (rotation == 3)) && (tmp_y > 0)))
					tmp_y--;
				break;
			case KEY_RIGHT:
				if (((rotation == 2) && (tmp_y + (size - 1) < 9))
					|| (((rotation == 1) || (rotation == 3) || (rotation == 4)) && (tmp_y < 9)))
					tmp_y++;
				break;
			case KEY_ROTATE:
				if (((rotation == 1) && ((tmp_y + (size - 1)) <= 9))
					|| ((rotation == 2) && ((tmp_x + (size - 1)) <= 9))
					|| ((rotation == 3) && ((tmp_y - (size - 1)) >= 0))
					|| ((rotation == 4) && ((tmp_x - (size - 1)) >= 0)))
					if (myField.canPlaceShip(tmp_x, tmp_y, rotation + 1, size))
						rotation = (rotation % 4) + 1;
				break;
			case KEY_END:
				if (myField.canPlaceShip(tmp_x, tmp_y, rotation, size)) {

					myField.placeShip(tmp_x, tmp_y, rotation, size);
					addShip(tmp_x, tmp_y, rotation, size);

					size--;
					if (size == 1) ships_placed = true;
				}
				else {
				}
				break;
			default:
				break;
			}
		}
	}
	else if (vriant == 2) {
		int tmp = 4;
		field tmp_field = myField;
		for (int size = 1; size < 5; size++) {
			for (int qnt = tmp; qnt > 0; qnt--) {
				bool ship_placed = false;
				while (!ship_placed) {
					PREVIEW.drawShip(tmp_x, tmp_y, size, rotation, myField);

					c = 0;
					switch ((c = _getch())) {
					case KEY_UP:
						if (((rotation == 1) && (tmp_x - (size - 1) > 0))
							|| (((rotation == 2) || (rotation == 3) || (rotation == 4)) && (tmp_x > 0)))
							tmp_x--;
						break;
					case KEY_DOWN:
						if (((rotation == 3) && (tmp_x + (size - 1) < 9))
							|| (((rotation == 1) || (rotation == 2) || (rotation == 4)) && (tmp_x < 9)))
							tmp_x++;
						break;
					case KEY_LEFT:
						if (((rotation == 4) && (tmp_y - (size - 1) > 0))
							|| (((rotation == 1) || (rotation == 2) || (rotation == 3)) && (tmp_y > 0)))
							tmp_y--;
						break;
					case KEY_RIGHT:
						if (((rotation == 2) && (tmp_y + (size - 1) < 9))
							|| (((rotation == 1) || (rotation == 3) || (rotation == 4)) && (tmp_y < 9)))
							tmp_y++;
						break;
					case KEY_ROTATE:
						if (((rotation == 1) && ((tmp_y + (size - 1)) <= 9))
							|| ((rotation == 2) && ((tmp_x + (size - 1)) <= 9))
							|| ((rotation == 3) && ((tmp_y - (size - 1)) >= 0))
							|| ((rotation == 4) && ((tmp_x - (size - 1)) >= 0)))
							if (myField.canPlaceShip(tmp_x, tmp_y, rotation + 1, size))
								rotation = (rotation % 4) + 1;
						break;
					case KEY_END:
						if (myField.canPlaceShip(tmp_x, tmp_y, rotation, size)) {
							ship_placed = true;
							myField.placeShip(tmp_x, tmp_y, rotation, size);
							addShip(tmp_x, tmp_y, rotation, size);
						}
						else {
						}
						break;
					default:
						break;
					}
				}
			}

			tmp--;
		}
	}
}
void player::makeShot(AI* ai) {
	Console->change_console_view(3, 20);
	cout << "Enter Number and Letter values:   ";
	Console->change_console_view(34, 20);
	int x;
	char cy;
	cin >> x >> cy;
	int y = (int)((int)cy > 90 ? (cy - 'a') : (cy - 'A'));
	int hit = ai->takeHit(x, y);
	if (hit == 0) {
		enemyField.setField(x, y, '.');
	}else if (hit == 1) {
		enemyField.setField(x, y, 'x');
		if ((x > 0) && (y > 0))
			enemyField.setField(x - 1, y - 1, '.');
		if ((x > 0) && (y < 9))
			enemyField.setField(x - 1, y + 1, '.');
		if ((x < 9) && (y > 0))
			enemyField.setField(x + 1, y - 1, '.');
		if ((x < 9) && (y < 9))
			enemyField.setField(x + 1, y + 1, '.');
	}else if (hit == 2) {
		enemyField.setField(x, y, 'X');
		if ((x > 0) && (y > 0))
			enemyField.setField(x - 1, y - 1, '.');
		if ((x > 0) && (y < 9))
			enemyField.setField(x - 1, y + 1, '.');
		if ((x < 9) && (y > 0))
			enemyField.setField(x + 1, y - 1, '.');
		if ((x < 9) && (y < 9))
			enemyField.setField(x + 1, y + 1, '.');

		if (x > 0)
			if (enemyField.getFieldAtPosition(x - 1, y) == '~')
				enemyField.setField(x - 1, y, '.');
		if (y > 0)
			if (enemyField.getFieldAtPosition(x, y - 1) == '~')
				enemyField.setField(x, y - 1, '.');
		if (x < 9)
			if (enemyField.getFieldAtPosition(x + 1, y) == '~')
				enemyField.setField(x + 1, y, '.');
		if (y < 9)
			if (enemyField.getFieldAtPosition(x, y + 1) == '~')
				enemyField.setField(x, y + 1, '.');
	}
}
