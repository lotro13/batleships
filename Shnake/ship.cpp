#include "pch.h"
#include "ship.h"


/*
	  ^(1)
<-(4)	   ->(2)
      V(3)
*/

ship::ship(int size, int rotation, int x_root, int y_root)
{
	hp = size;
	for (int i = 0; i < size; i++) {
		x.push_back(x_root);
		y.push_back(y_root);
		switch (rotation)
		{
		case 1:
			x_root--;
			break;
		case 2:
			y_root++;
			break;
		case 3:
			x_root++;
			break;
		case 4:
			y_root--;
			break;
		default:
			break;
		}
		symbol.push_back('#');
	}
}

int ship::getX(int i) {
	return x[i];
}
int ship::getY(int i) {
	return y[i];
}
int ship::getRotation() {
	return rotation;
}
char ship::getSymbol(int i) {
	return symbol[i];
}
void ship::setSymbol(int i, char s) {
	symbol[i] = s;
}
int ship::getHP() {
	return hp;
}
int ship::getSize() {
	return symbol.size();
}

// 0 - miss, 1 - hit, 2 - already damaged
int ship::takeHit(int hit_x, int hit_y) {
	for (int i = 0; i < symbol.size(); i++) {
		if ((x[i] == hit_x) && (y[i] == hit_y)) {
			if (symbol[i] == '#') {
				return 1;
			}
			else {
				return 2;
			}
		}
	}
	return 0;
}