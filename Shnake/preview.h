#pragma once
class preview
{
private:
	field f;
	console* Console;
	int x;
	int y;
	int r;
	int s;
public:
	preview(console*);
	void drawShip(int, int, int, int, field);
	//void moveShip(int);
};

