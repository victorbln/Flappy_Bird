#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "Functions.h"
#include <iostream>
#include <windows.h>
#include "Data.h"
#include "Bird.h"
#include <thread>
#include <vector>
#include "flip_pipe.h"
#include<conio.h>
#include<dos.h>
#include <chrono>
#include<stdlib.h>
#include<string.h>
#include "Pipe.h"
#include "Timer.h"


void coordonate(int x, int y);//function that sets the cursor of the console at some specified coordinates
void Flappy_Bird();//main meniu function of the game
void SetColor(int color_code);//function that chenge the color of the text displayed on the console
void Play();//the function which contains the game logic and functionality
void chenar();//function which creates a blank window with edges
void ShowConsoleCursor(bool showFlag);//function which hides the cursor in the console


#endif

