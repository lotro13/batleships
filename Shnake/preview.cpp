#include "pch.h"
#include "preview.h"
#include "console.h"
#include "field.h"


preview::preview(console* C)
{
	this->Console = C;
}
void preview::drawShip(int x, int y, int s, int r, field f) {
	this->x = x;
	this->y = y;
	this->s = s;
	this->r = r;


	Console->print(f, 10, 7);

	int tmp_x = x;
	int tmp_y = y;
	switch (r)
	{
	case 1:
		for (int i = 0; i < s; i++) {
			Console->print('#', (tmp_y * 2) + 10, tmp_x + 7);
			tmp_x--;
		}
		break;
	case 2:
		for (int i = 0; i < s; i++) {
			Console->print('#', (tmp_y * 2) + 10, tmp_x + 7);
			tmp_y++;
		}
		break;
	case 3:
		for (int i = 0; i < s; i++) {
			Console->print('#', (tmp_y * 2) + 10, tmp_x + 7);
			tmp_x++;
		}
		break;
	case 4:
		for (int i = 0; i < s; i++) {
			Console->print('#', (tmp_y * 2) + 10, tmp_x + 7);
			tmp_y--;
		}
		break;
	default:
		break;
	}
}
/*
void preview::moveShip(int vector) {
	switch (vector) {
	case 1:

		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		r++;
		break;
	}
} */
//1 - up 2 - right 3 - down 4 - left 5 - rotate