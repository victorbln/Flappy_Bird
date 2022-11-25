#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <windows.h>
#include "flip_pipe.h"
#include "Pipe.h"
#include "User.h"
#include <fstream>
#include "Functions.h"
#include "Bird.h"
#include "Timer.h"
#include "User.h"
//#include <string.h>
static double var_time = 0.15;//time interval between 2 moves of the pipes
static double bird_time_var = 0.25;//time interval for bird 
static int move_count = 0;//pipes moves counter
static int pipes = 0;//number of pipes
static int gap = 6;//gap between pipes
static long long highest_score = 0;
static int score = 0;
static int attempts = 0;


static std::fstream database;
// static User* users[10];
//static User *user1;

static std::string user_name="";
static std::string password="";
static int guest = 1;
static bool acces = false;



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
  //                  <"_/   }



#endif
