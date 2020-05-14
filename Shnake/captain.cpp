#include "pch.h"
#include "captain.h"
#include "field.h"
#include <vector>

using namespace std;

bool captain::loose() {
	if (HP == 0)
		return true;
	else
		return false;
}
int captain::takeHit(int hit_take_x, int hit_take_y) {
	for(int i = 0; i < fleet.size(); i++)
		for (int j = 0; j < fleet[i].x.size(); j++) {
			if ((fleet[i].x[j] == hit_take_x) && (fleet[i].y[j] == hit_take_y)) {
				myField.setField(hit_take_x, hit_take_y, 'X');

				for (int l = 0; l < fleet[i].x.size(); l++) {
					if (myField.getFieldAtPosition(fleet[i].x[l], fleet[i].y[l]) == '#')
						return 1;
				}
				return 2;
			}
		}
	myField.setField(hit_take_x, hit_take_y, '.');
	return 0;
}
/*void captain::makeShot(captain* TARGET) {
}*/
field captain::getMyField() {
	return myField;
}
field captain::getEnemyField() {
	return enemyField;
}
int captain::getHP() {
	int tmp = 0;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (myField.getFieldAtPosition(i, j) == '#') 
				tmp++;

	return tmp;
}

void captain::addShip(int tmp_x, int tmp_y, int rotation, int size) {
	ship S;
	for (int i = 0; i < size; i++) {
		S.x.push_back(tmp_x);
		S.y.push_back(tmp_y);

		switch (rotation)
		{
		case 1:
			tmp_x--;
			break;
		case 2:
			tmp_y++;
			break;
		case 3:
			tmp_x++;
			break;
		case 4:
			tmp_y--;
			break;
		default:
			break;
		}
	}
	fleet.push_back(S);
}
void captain::addShip(ship* S, int tmp_x, int tmp_y, int rotation, int size) {
	for (int i = 0; i < size; i++) {
		S->x.push_back(tmp_x);
		S->y.push_back(tmp_y);

		switch (rotation)
		{
		case 1:
			tmp_x--;
			break;
		case 2:
			tmp_y++;
			break;
		case 3:
			tmp_x++;
			break;
		case 4:
			tmp_y--;
			break;
		default:
			break;
		}
	}
}
void captain::setFleet(std::vector<ship>* tmp_fleet) {
	/*
			Overload the = operator, PLZ
	fleet = tmp_fleet;
	*/
}
/*
vector<ship>& captain::operator=(std::vector<ship>& tmp_fleet)
{
	std::vector<ship> tmp;
}
*/