#pragma once
#include <iostream>
#include <string.h>
#include <SFML/Graphics.hpp>
#include <vector>
#include <time.h>
#include <sstream>
using namespace std;
using namespace sf;

int howmany(int x, int* map);
bool check(int x, int* map);
void prepare(int *map, int bombs);
Vector2f GetMousPosition(Window *W);
