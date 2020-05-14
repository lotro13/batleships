#include "pch.h"
#include "field.h"


/*
 Y-----------------
X
|
|
|
*/

field::field()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			battlefield[i][j] = '~';
}
char field::getFieldAtPosition(int x, int y) {
	return battlefield[x][y];
}
void field::setField(int x, int y, char c) {
	battlefield[x][y] = c;
}

bool field::isTaken(int x, int y) {
	if (battlefield[x][y] == '~') {
		if (x > 0)
			if (!(battlefield[x - 1][y] == '~')) return true;
		if (x < 9)
			if (!(battlefield[x + 1][y] == '~')) return true;
		if (y > 0)
			if (!(battlefield[x][y - 1] == '~')) return true;
		if (y < 9)
			if (!(battlefield[x][y + 1] == '~')) return true;
		if ((x > 0) && (y > 0))
			if (!(battlefield[x - 1][y - 1] == '~')) return true;
		if ((x > 0) && (y < 9))
			if (!(battlefield[x - 1][y + 1] == '~')) return true;
		if ((x < 9) && (y > 0))
			if (!(battlefield[x + 1][y - 1] == '~')) return true;
		if ((x < 9) && (y < 9))
			if (!(battlefield[x + 1][y + 1] == '~')) return true;
		return false;
	}
	return true;
}
bool field::canPlaceShip(int x, int y, int r, int s) {
	for (int i = 0; i < s; i++) {
		if (isTaken(x, y)) return false;
		switch (r)
		{
		case 1:
			x--;
			break;
		case 2:
			y++;
			break;
		case 3:
			x++;
			break;
		case 4:
			y--;
			break;
		default:
			break;
		}
	}
	return true;
}
void field::placeShip(int x, int y, int r, int s) {
	for (int i = 0; i < s; i++) {
		battlefield[x][y] = '#';
		switch (r)
		{
		case 1:
			x--;
			break;
		case 2:
			y++;
			break;
		case 3:
			x++;
			break;
		case 4:
			y--;
			break;
		default:
			break;
		}
	}
}