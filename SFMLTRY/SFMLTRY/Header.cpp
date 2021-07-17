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
void IfHowManyNull(int x, int* map, vector<RectangleShape>& V, vector<Text>& H,Text &H2)
{
	if (V[x].getFillColor() != Color(255, 255, 255))
	{
		


		V[x].setFillColor(Color(255, 255, 255));


		if (x < 9 && x>0)
		{
			if (howmany(x - 1, map) == 0)IfHowManyNull(x - 1, map, V, H, H2); else others(x-1, map, V, H, H2);
			if (howmany(x + 1, map) == 0 )IfHowManyNull(x + 1, map, V, H, H2); else others(x+1, map, V, H, H2);
			if (howmany(x + 9, map) == 0 )IfHowManyNull(x + 9, map, V, H, H2); else others(x+9, map, V, H, H2);
			if (howmany(x + 10, map) == 0 )IfHowManyNull(x + 10, map, V, H, H2); else others(x+10, map, V, H, H2);
			if (howmany(x + 11, map) == 0 )IfHowManyNull(x + 11, map, V, H, H2); else others(x+11, map, V, H, H2);

		}
		else if (x < 99 && x>90)
		{
			if (howmany(x - 11, map) == 0 )IfHowManyNull(x - 11, map, V, H, H2); else others(x-11, map, V, H, H2);
			if (howmany(x - 10, map) == 0 )IfHowManyNull(x - 10, map, V, H, H2); else others(x-10, map, V, H, H2);
			if (howmany(x - 9, map) == 0 )IfHowManyNull(x - 9, map, V, H, H2); else others(x-9, map, V, H, H2);
			if (howmany(x + 1, map) == 0 )IfHowManyNull(x + 1, map, V, H, H2); else others(x+1, map, V, H, H2);
			if (howmany(x - 1, map) == 0 )IfHowManyNull(x - 1, map, V, H, H2); else others(x-1, map, V, H, H2);

		}
		else if (x == 0)
		{
			if (howmany(x + 1, map) == 0 )IfHowManyNull(x + 1, map, V, H, H2); else others(x+1, map, V, H, H2);
			if (howmany(x + 10, map) == 0 )IfHowManyNull(x + 10, map, V, H, H2); else others(x+10, map, V, H, H2);
			if (howmany(x + 11, map) == 0 )IfHowManyNull(x + 11, map, V, H, H2); else others(x+11, map, V, H, H2);

		}
		else if (x == 9)
		{
			if (howmany(x - 1, map) == 0 )IfHowManyNull(x - 1, map, V, H, H2); else others(x-1, map, V, H, H2);
			if (howmany(x + 10, map) == 0 )IfHowManyNull(x + 10, map, V, H, H2); else others(x+10, map, V, H, H2);
			if (howmany(x + 9, map) == 0 )IfHowManyNull(x + 9, map, V, H, H2); else others(x+9, map, V, H, H2);

		}
		else if (x == 90)
		{
			if (howmany(x - 10, map) == 0 )IfHowManyNull(x - 10, map, V, H, H2); else others(x-10, map, V, H, H2);
			if (howmany(x + 1, map) == 0 )IfHowManyNull(x + 1, map, V, H, H2); else others(x+1, map, V, H, H2);
			if (howmany(x - 9, map) == 0 )IfHowManyNull(x - 9, map, V, H, H2); else others(x-9, map, V, H, H2);

		}
		else if (x == 99)
		{
			if (howmany(x - 10, map) == 0 )IfHowManyNull(x - 10, map, V, H, H2); else others(x-10, map, V, H, H2);
			if (howmany(x - 11, map) == 0 )IfHowManyNull(x - 11, map, V, H, H2); else others(x-11, map, V, H, H2);
			if (howmany(x - 1, map) == 0 )IfHowManyNull(x - 1, map, V, H, H2); else others(x-1, map, V, H, H2);

		}
		else if (x % 10 == 0)
		{
			if (howmany(x - 10, map) == 0 )IfHowManyNull(x - 10, map, V, H, H2); else others(x-10, map, V, H, H2);
			if (howmany(x - 9, map) == 0 )IfHowManyNull(x - 9, map, V, H, H2); else others(x-9, map, V, H, H2);
			if (howmany(x + 1, map) == 0 )IfHowManyNull(x + 1, map, V, H, H2); else others(x+1, map, V, H, H2);
			if (howmany(x + 11, map) == 0 )IfHowManyNull(x + 11, map, V, H, H2); else others(x+11, map, V, H, H2);
			if (howmany(x + 10, map) == 0 )IfHowManyNull(x + 10, map, V, H, H2); else others(x+10, map, V, H, H2);

		}
		else if (x % 10 == 9)
		{
			if (howmany(x - 10, map) == 0 )IfHowManyNull(x - 10, map, V, H, H2); else others(x-10, map, V, H, H2);
			if (howmany(x - 11, map) == 0 )IfHowManyNull(x - 11, map, V, H, H2); else others(x-11, map, V, H, H2);
			if (howmany(x - 1, map) == 0 )IfHowManyNull(x - 1, map, V, H, H2); else others(x-1, map, V, H, H2);
			if (howmany(x + 10, map) == 0 )IfHowManyNull(x + 10, map, V, H, H2); else others(x+10, map, V, H, H2);
			if (howmany(x + 9, map) == 0 )IfHowManyNull(x + 9, map, V, H, H2); else others(x+9, map, V, H, H2);

		}
		else
		{

			if (howmany(x - 1, map) == 0 )IfHowManyNull(x - 1, map, V, H, H2); else others(x-1, map, V, H, H2);
			if (howmany(x + 1, map) == 0 )IfHowManyNull(x + 1, map, V, H, H2); else others(x+1, map, V, H, H2);
			if (howmany(x + 11, map) == 0 )IfHowManyNull(x + 11, map, V, H, H2); else others(x+11, map, V, H, H2);
			if (howmany(x + 10, map) == 0 )IfHowManyNull(x + 10, map, V, H, H2); else others(x+10, map, V, H, H2);
			if (howmany(x + 9, map) == 0 )IfHowManyNull(x + 9, map, V, H, H2); else others(x+9, map, V, H, H2);
			if (howmany(x - 11, map) == 0 )IfHowManyNull(x - 11, map, V, H, H2); else others(x-11, map, V, H, H2);
			if (howmany(x - 10, map) == 0 )IfHowManyNull(x - 10, map, V, H, H2); else others(x-10, map, V, H, H2);
			if (howmany(x - 9, map) == 0 )IfHowManyNull(x - 9, map, V, H, H2); else others(x-9, map, V, H, H2);



		}

	}
}
void others(int x, int* map, vector<RectangleShape>& V, vector<Text> &H, Text& H2)
{
	if (V[x].getFillColor() != Color(255, 255, 255))
	{
		
		stringstream ss;
		V[x].setFillColor(Color(255, 255, 255));
		ss.str("");
		ss << howmany(x, map);
		H2.setString(ss.str());
		H2.setPosition(V[x].getPosition().x + 10, V[x].getPosition().y);
		H.push_back(H2);
		
	}
}
