#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <windows.h>
#include <vector>
#include "flip_pipe.h"
#include "Pipe.h"
static double var_time = 0.3;//time interval between 2 moves of the pipes
static int move_count = 0;//pipes moves counter
static int pipes = 0;//number of pipes
static int gap = 6;//gap between pipes

static Pipe* down_pipes[5];//array of pointer to objects of type down_pipe
static flip_pipe* up_pipes[5];//array of pointer to objects of type up_pipe


static COORD CursorPosition;//variable of type COORD which contains the coordinates of the cursor
static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);///console handler used for colorizing output texts
static CONSOLE_SCREEN_BUFFER_INFO csbi;//variable which stores the screen buffer info(c console + s screen + b buffer + i info = csbi)

static char pipe[2][8] = { '\xDB','\xDB','\xDB','\xDB','\xDB','\xDB','\xDB',//head of the pipe
                      ' ','\xDB','\xDB','\xDB','\xDB','\xDB',' ' };//body of the pipe

static char bird[2][7] = { ' ',' ','(',' ','o',')','>',
                    ' ','<','"','_','/',' ',' ' };//bird body array
//char bird[2][7] = {  ( o)>
  //                  <"_/   ;



#endif
