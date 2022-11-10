#include "Bird.h"
#include <iostream>
#include <windows.h>
#include "Data.h"
#include "Functions.h"
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
Bird::Bird()
{
	SetColor(6);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 7; j++) {
			coordonate(10+j, 10+i);
			m_bird[i][j] = bird[i][j];
			std::cout << bird[i][j];
		}
	}
	y1 = 10;
	y2 = 10;
}


int Bird::move_bird(char ch) {
	if (ch == 32) {
		if (y2 > 4)
		{
			y2 -= 1;
			return 1;
		}
		return 0;
	}
}
void Bird::update_pos()
{
	ShowConsoleCursor(false);
	SetColor(6);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 7; j++) {
			coordonate(y1 + j, y2 + i);
			std::cout << bird[i][j];
		}
	}
	coordonate(10, y2+2); std::cout << "       ";
}
void Bird::hit() 
{
	/*for (int i = n; i <= 19; i++)
	{
		for (j = x; j <= x + 7; j++) {
			if (ok != 1) {
				coordonate(j - 1, i); std::cout << pipe[0][k];
			}
			else {
				coordonate(j, i); std::cout << pipe[1][k];
			}
			k++;
		}
		coordonate(j + 1, i); std::cout << " ";
		k = 0;
		ok = 1;
	}*/
}
bool Bird::fall() 
{
	ShowConsoleCursor(false);
	SetColor(6);
	if (y2 < 19) {
	y2 += 1;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 7; j++) {
				coordonate(y1 + j, y2 + i);
				std::cout << bird[i][j];
			}
		}
		coordonate(10, y2 - 1); std::cout << "       ";
		return false;
	}
	else {
		return true;
	}
}

bool Bird::game_over() {

	if (y2 == 19) {
		return true;
	}
	else {
		return false;
	}
}
Bird::~Bird()
{
}
