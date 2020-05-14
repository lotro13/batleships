#include "pch.h"
#pragma once
class animation {
private:
	int x;
	int y;
	char sequence[4];
	char end_char;
public:
	animation(int x, int y, char s);
	void draw_animation(char field[10][10]);
};