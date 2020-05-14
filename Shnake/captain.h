#pragma once

class captain
{
protected:
	int HP;
	field myField;
	field enemyField;
	struct ship {
		std::vector<int> x;
		std::vector<int> y;
	};
	std::vector<ship> fleet;
public: 
	bool loose();
	int takeHit(int, int);
	//void makeShot();
	field getMyField();
	field getEnemyField();
	int getHP();
	void addShip(int, int, int, int);
	void addShip(ship*, int, int, int, int);
	void setFleet(std::vector<ship>*);
	//vector<ship>& operator=(std::vector<ship> &tmp_fleet);
};

/*
	Take Hit Results:
0 - miss
1 - hit
2 - destroy

*/
