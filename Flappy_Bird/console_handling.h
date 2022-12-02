#ifndef CONSOLE_HANDLING_H
#define CONSOLE_HANDLING_H
#include <Windows.h>
#include <iostream>
class console_handling
{
	COORD CursorPosition;//variable of type COORD which contains the coordinates of the cursor
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);///console handler used for colorizing output texts
	CONSOLE_SCREEN_BUFFER_INFO csbi;//variable which stores the screen buffer info(c console + s screen + b buffer + i info = csbi)
public:
	void coordonate(int x, int y);//function that sets the cursor of the console at some specified coordinates
	void SetColor(int color_code);//function that chenge the color of the text displayed on the console
	void chenar();//function which creates a blank window with edges
	void ShowConsoleCursor(bool showFlag);//function which hides the cursor in the console
};	

#endif