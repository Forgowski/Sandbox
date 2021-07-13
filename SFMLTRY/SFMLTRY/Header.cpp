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
void prepare(int *map)
{
	srand(time(0));				//mapa gry z bombami
	for (int i = 0; i < 100; i++)
	{
		map[i] = 0;
	}
	for (int i = 0; i < 20; i++)    //ilosc bomb
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