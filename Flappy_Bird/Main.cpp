#include <iostream>
#include <windows.h>
#include "Flappy_bird.h"


int main() 
{
	SetConsoleTitle(L"Flappy Bird");

	flappy_bird *f=new flappy_bird;
	f->login_meniu();

	return 0;
}