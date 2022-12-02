#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "flip_pipe.h"
#include "console_handling.h"
#include "Pipe.h"
#include "Bird.h"
#include "Timer.h"
#include "User.h"

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <string.h>

class functions : public console_handling
{
	Pipe* down_pipes[5];//array of pointer to objects of type down_pipe
	flip_pipe* up_pipes[5];//array of pointer to objects of type up_pipe


	User* user1;//creating global user for 1 instance of the game

	double var_time = 0.15;//time interval between 2 moves of the pipes
	double bird_time_var = 0.25;//time interval for bird 
	int move_count = 0;//pipes moves counter
	int pipes = 0;//number of pipes
	

	int highest_score = 0;
	int score = 0;
	int attempts = 0;

	//login used variables
	
	std::string user_name = "";
	int guest = 1;
	bool acces = false;

public:
	void Flappy_Bird();//main meniu function of the game
	void Play();//the function which contains the game logic and functionality
	void instructions();
	void login_meniu();
	int m_get_score() { return score; }
};
#endif

