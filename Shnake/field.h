#pragma once
class field
{
private:
	char battlefield[10][10];
public:
	field();
	char getFieldAtPosition(int, int);
	void setField(int, int, char);
	bool isTaken(int, int);
	bool canPlaceShip(int, int, int, int);
	void placeShip(int, int, int,int);
};

/*
   0 1 2  
0  + + +
1  + + +
2  + + +
*/

/*
 YYYYYYY
X
X
X
*/

/*
	  ^(1)
<-(4)	   ->(2)
	  V(3)
*/

/*
1 - x-- 
2 - y++
3 - x++
4 - y--
*/
