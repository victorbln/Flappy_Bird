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

class flappy_bird : public console_handling
{
	Pipe* down_pipes[5];//array of pointer to objects of type down_pipe
	flip_pipe* up_pipes[5];//array of pointer to objects of type up_pipe


	User* user1;//creating global user for 1 instance of the game

	//in game used variables
	double var_time = 0.15;//time interval between 2 moves of the pipes
	double bird_time_var = 0.25;//time interval for bird 
	int move_count = 0;//pipes moves counter
	int pipes = 0;//number of pipes
	int highest_score = 0;//the highest score of the user
	int score = 0;//the score of the user in the current sesion or attempt 
	int attempts = 0;//number of attempts after the log in

	//login used variables
	std::string user_name = "";//username
	bool guest = 1;//bool variable that will be interogated to know if the game is played by a registered user or by just a guest who just wants to have fun
	bool acces = false;//bool variable that is set to true if the user loged in succesfully
public:


	void Flappy_Bird();//main meniu function of the game
	void Play();//the function which contains the game logic and functionality
	void instructions();//method that shows the instructions of the game
	void login_meniu();//method that displays the log in meniu
	int m_get_score() { return score; }//method that returns the score of the user
};
#endif

