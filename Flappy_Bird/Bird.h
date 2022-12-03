#ifndef BIRD_H
#define BIRD_H
#include <iostream>

#include "flip_pipe.h"
#include "Pipe.h"
#include "console_handling.h"


class Bird : public console_handling
{
	const char bird[2][7] = { ' ',' ','(',' ','o',')','>',
						' ','<','"','_','/',' ',' ' };
	//char bird[2][7] = {  ( o)>
	//bird body array     <"_/   }
	int m_x;//bird pozition on x axis
	int m_y;//bird position on y axis
public:

	Bird();
	~Bird();
	int move_bird(char ch);//method that is triggered when the user presses a key...if it is space the bird moves one space up
	bool game_over(Pipe* down_pipe[], flip_pipe* up_pipe[]);//method that checks if the bird hit one of the pipes..if so the game ends
	bool fall();//method that is called after a certain period of time to make the bird fall 1 space

	};

#endif