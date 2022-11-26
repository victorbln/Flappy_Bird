#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <windows.h>
#include <fstream>

#include "flip_pipe.h"
#include "Pipe.h"
#include "User.h"
#include "Bird.h"
#include "Timer.h"
#include "User.h"
//game functions variables
static double var_time = 0.15;//time interval between 2 moves of the pipes
static double bird_time_var = 0.25;//time interval for bird 
static int move_count = 0;//pipes moves counter
static int pipes = 0;//number of pipes
static int gap = 6;//gap between pipes
static int highest_score = 0;
static int score = 0;
static int attempts = 0;

//login used variables
static std::fstream database;
static std::string user_name="";
static std::string password="";
static int guest = 1;
static bool acces = false;


//storage variables
static Pipe* down_pipes[5];//array of pointer to objects of type down_pipe
static flip_pipe* up_pipes[5];//array of pointer to objects of type up_pipe

//console manipulation variables
static COORD CursorPosition;//variable of type COORD which contains the coordinates of the cursor
static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);///console handler used for colorizing output texts
static CONSOLE_SCREEN_BUFFER_INFO csbi;//variable which stores the screen buffer info(c console + s screen + b buffer + i info = csbi)


#endif
