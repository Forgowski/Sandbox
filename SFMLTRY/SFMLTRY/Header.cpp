#include "Header.h"


int howmany(int x, int* map)
{

	int bombs = 0;
	if (x < 9 && x>0)
	{
		if (map[x - 1] == 1)bombs++;
		if (map[x + 1] == 1)bombs++;
		if (map[x + 9] == 1)bombs++;
		if (map[x + 10] == 1)bombs++;
		if (map[x + 11] == 1)bombs++;
		return bombs;
	}
	else if (x < 99 && x>90)
	{
		if (map[x - 11] == 1)bombs++;
		if (map[x - 10] == 1)bombs++;
		if (map[x - 9] == 1)bombs++;
		if (map[x + 1] == 1)bombs++;
		if (map[x - 1] == 1)bombs++;
		return bombs;
	}
	else if (x == 0)
	{
		if (map[x + 1] == 1)bombs++;
		if (map[x + 10] == 1)bombs++;
		if (map[x + 11] == 1)bombs++;
		return bombs;
	}
	else if (x == 9)
	{
		if (map[x - 1] == 1)bombs++;
		if (map[x + 10] == 1)bombs++;
		if (map[x + 9] == 1)bombs++;
		return bombs;
	}
	else if (x == 90)
	{
		if (map[x - 10] == 1)bombs++;
		if (map[x + 1] == 1)bombs++;
		if (map[x - 9] == 1)bombs++;
		return bombs;
	}
	else if (x == 99)
	{
		if (map[x - 10] == 1)bombs++;
		if (map[x - 11] == 1)bombs++;
		if (map[x - 1] == 1)bombs++;
		return bombs;
	}
	else if (x % 10 == 0)
	{
		if (map[x - 10] == 1)bombs++;
		if (map[x - 9] == 1)bombs++;
		if (map[x + 1] == 1)bombs++;
		if (map[x + 11] == 1)bombs++;
		if (map[x + 10] == 1)bombs++;
		return bombs;
	}
	else if (x % 10 == 9)
	{
		if (map[x - 10] == 1)bombs++;
		if (map[x - 11] == 1)bombs++;
		if (map[x - 1] == 1)bombs++;
		if (map[x + 10] == 1)bombs++;
		if (map[x + 9] == 1)bombs++;
		return bombs;
	}
	else
	{
		if (map[x - 1] == 1)bombs++;
		if (map[x + 1] == 1)bombs++;
		if (map[x + 11] == 1)bombs++;
		if (map[x + 10] == 1)bombs++;
		if (map[x + 9] == 1)bombs++;
		if (map[x - 11] == 1)bombs++;
		if (map[x - 10] == 1)bombs++;
		if (map[x - 9] == 1)bombs++;
		return bombs;


	}
}
bool check(int x, int* map)
{
	if (map[x] == 1)
	{
		map[x] == 0;
		return true;
	}
	else return false;
}
void prepare(int *map,int bombs)
{
	if (bombs < 5 || bombs>90) bombs = 20;

	srand(time(0));				//mapa gry z bombami
	for (int i = 0; i < 100; i++)
	{
		map[i] = 0;
	}
	for (int i = 0; i < bombs; i++)    //ilosc bomb
	{
		int f;
		f = rand() % 100;
		if (map[f] == 0)  map[f] = 1;

		else i--;

	}
	
}
Vector2f GetMousPosition(Window *W)
{
	return Vector2f(Mouse::getPosition(*W));
}
void IfHowManyNull(int x,int *map, vector<RectangleShape>& V)
{

 V[x].setFillColor(Color(255, 255, 255));

	if (x < 9 && x>0)
	{
		if (howmany(x - 1,map)==0 && V[x - 1].getFillColor() != Color(255, 255, 255))IfHowManyNull(x-1,map, V);
		if (howmany(x + 1, map) == 0 && V[x + 1].getFillColor() != Color(255, 255, 255))IfHowManyNull(x + 1, map, V);
		if (howmany(x + 9, map) == 0 && V[x + 9].getFillColor() != Color(255, 255, 255))IfHowManyNull(x + 9, map, V);
		if (howmany(x + 10, map) == 0 && V[x + 10].getFillColor() != Color(255, 255, 255))IfHowManyNull(x + 10, map, V);
		if (howmany(x + 11, map) == 0 && V[x + 11].getFillColor() != Color(255, 255, 255))IfHowManyNull(x + 11, map, V);
		
	}
	else if (x < 99 && x>90)
	{
		if (howmany(x - 11, map) == 0 && V[x - 11].getFillColor() != Color(255, 255, 255))IfHowManyNull(x - 11, map, V);
		if (howmany(x - 10, map) == 0 && V[x - 10].getFillColor() != Color(255, 255, 255))IfHowManyNull(x - 10, map, V);
		if (howmany(x - 9, map) == 0 && V[x - 9].getFillColor() != Color(255, 255, 255))IfHowManyNull(x - 9, map, V);
		if (howmany(x + 1, map) == 0 && V[x + 1].getFillColor() != Color(255, 255, 255))IfHowManyNull(x + 1, map, V);
		if (howmany(x - 1, map) == 0 && V[x - 1].getFillColor() != Color(255, 255, 255))IfHowManyNull(x - 1, map, V);
		
	}
	else if (x == 0)
	{
		if (howmany(x + 1, map) == 0 && V[x + 1].getFillColor() != Color(255, 255, 255))IfHowManyNull(x + 1, map, V);
		if (howmany(x + 10, map) == 0 && V[x + 10].getFillColor() != Color(255, 255, 255))IfHowManyNull(x + 10, map, V);
		if (howmany(x + 11, map) == 0 && V[x + 11].getFillColor() != Color(255, 255, 255))IfHowManyNull(x + 11, map, V);
		
	}
	else if (x == 9)
	{
		if (howmany(x - 1, map) == 0 && V[x - 1].getFillColor() != Color(255, 255, 255))IfHowManyNull(x - 1, map, V);
		if (howmany(x + 10, map) == 0 && V[x + 10].getFillColor() != Color(255, 255, 255))IfHowManyNull(x + 10, map, V);
		if (howmany(x + 9, map) == 0 && V[x + 9].getFillColor() != Color(255, 255, 255))IfHowManyNull(x + 9, map, V);
		
	}
	else if (x == 90)
	{
		if (howmany(x - 10, map) == 0 && V[x - 10].getFillColor() != Color(255, 255, 255))IfHowManyNull(x - 10, map, V);
		if (howmany(x + 1, map) == 0 && V[x + 1].getFillColor() != Color(255, 255, 255))IfHowManyNull(x + 1, map, V);
		if (howmany(x - 9, map) == 0 && V[x - 9].getFillColor() != Color(255, 255, 255))IfHowManyNull(x - 9, map, V);
		
	}
	else if (x == 99)
	{
		if (howmany(x - 10, map) == 0 && V[x - 10].getFillColor() != Color(255, 255, 255))IfHowManyNull(x - 10, map, V);
		if (howmany(x - 11, map) == 0 && V[x - 11].getFillColor() != Color(255, 255, 255))IfHowManyNull(x - 11, map, V);
		if (howmany(x - 1, map) == 0 && V[x - 1].getFillColor() != Color(255, 255, 255))IfHowManyNull(x - 1, map, V);
		
	}
	else if (x % 10 == 0)
	{
		if (howmany(x - 10, map) == 0 && V[x - 10].getFillColor() != Color(255, 255, 255))IfHowManyNull(x - 10, map, V);
		if (howmany(x - 9, map) == 0 && V[x - 9].getFillColor() != Color(255, 255, 255))IfHowManyNull(x - 9, map, V);
		if (howmany(x + 1, map) == 0 && V[x + 1].getFillColor() != Color(255, 255, 255))IfHowManyNull(x + 1, map, V);
		if (howmany(x + 11, map) == 0 && V[x + 11].getFillColor() != Color(255, 255, 255))IfHowManyNull(x + 11, map, V);
		if (howmany(x + 10, map) == 0 && V[x + 10].getFillColor() != Color(255, 255, 255))IfHowManyNull(x + 10, map, V);
		
	}
	else if (x % 10 == 9)
	{
		if (howmany(x - 10, map) == 0 && V[x - 10].getFillColor() != Color(255, 255, 255))IfHowManyNull(x - 10, map, V);
		if (howmany(x - 11, map) == 0 && V[x - 11].getFillColor() != Color(255, 255, 255))IfHowManyNull(x - 11, map, V);
		if (howmany(x - 1, map) == 0 && V[x - 1].getFillColor() != Color(255, 255, 255))IfHowManyNull(x - 1, map, V);
		if (howmany(x + 10, map) == 0 && V[x + 10].getFillColor() != Color(255, 255, 255))IfHowManyNull(x + 10, map, V);
		if (howmany(x + 9, map) == 0 && V[x + 9].getFillColor() != Color(255, 255, 255))IfHowManyNull(x + 9, map, V);
		
	}
	else
	{
		
		if (howmany(x - 1, map) == 0 && V[x - 1].getFillColor() != Color(255, 255, 255))IfHowManyNull(x - 1, map, V);
		if (howmany(x + 1, map) == 0 && V[x + 1].getFillColor() != Color(255, 255, 255))IfHowManyNull(x + 1, map, V);
		if (howmany(x + 11, map) == 0 && V[x + 11].getFillColor() != Color(255, 255, 255))IfHowManyNull(x + 11, map, V);
		if (howmany(x + 10, map) == 0 && V[x + 10].getFillColor() != Color(255, 255, 255))IfHowManyNull(x + 10, map, V);
		if (howmany(x + 9, map) == 0 && V[x + 9].getFillColor() != Color(255, 255, 255))IfHowManyNull(x + 9, map, V);
		if (howmany(x - 11, map) == 0 && V[x - 11].getFillColor() != Color(255, 255, 255))IfHowManyNull(x - 11, map, V);
		if (howmany(x - 10, map) == 0 && V[x - 10].getFillColor() != Color(255, 255, 255))IfHowManyNull(x - 10, map, V);
		if (howmany(x - 9, map) == 0 && V[x - 9].getFillColor() != Color(255, 255, 255))IfHowManyNull(x - 9, map, V);
		


	}
}