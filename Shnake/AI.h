#pragma once

class AI : public captain
{
public:
	AI();
	void placeShips(int);
	vector<int> makeShot();
	void analise(int, int, int);
};


