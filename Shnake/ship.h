#pragma once
#include <vector>
using namespace std;
class ship
{
private:
	vector<int> x;
	vector<int> y;
	int rotation;
	vector<char> symbol;
	int hp;
public:
	ship(int, int, int, int);
	int getX(int);
	int getY(int);
	int getRotation();
	char getSymbol(int);
	void setSymbol(int, char);
	int getHP();
	int getSize();
	int takeHit(int, int);
};