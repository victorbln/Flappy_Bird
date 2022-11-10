#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <windows.h>
#include <vector>
#include "flip_pipe.h"
#include "Pipe.h"
static double var_time = 0.3;
#define GAP 5
static int move_count = 0;
static int pipes = 0;
static std::vector<Pipe> down_pipes;
static std::vector<flip_pipe> up_pipes;
static std::vector<Pipe>::iterator pipe_it;
static std::vector<flip_pipe>::iterator flip_pipe_it;
static COORD CursorPosition;
static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);///console handler used for colorizing output texts
static CONSOLE_SCREEN_BUFFER_INFO csbi;//variable which stores the screen buffer info
static char pipe[2][8] = { '\xDB','\xDB','\xDB','\xDB','\xDB','\xDB','\xDB',
                      ' ','\xDB','\xDB','\xDB','\xDB','\xDB',' ' };
static char bird[2][7] = { ' ',' ','(',' ','o',')','>',
                    ' ','<','"','_','/',' ',' ' };
//char bird[2][7] = {  ( o)>
  //                  <"_/   ;



#endif
