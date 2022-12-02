#ifndef BIRD_H
#define BIRD_H
#include "flip_pipe.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>

#include "Pipe.h"
#include "console_handling.h"
#include "Flappy_bird.h"

class Bird : public console_handling
{
	const char bird[2][7] = { ' ',' ','(',' ','o',')','>',
						' ','<','"','_','/',' ',' ' };
	//char bird[2][7] = {  ( o)>
	//bird body array     <"_/   }
	int m_x;
	int m_y;
public:

	Bird();
	~Bird();
	void move_bird(char ch);
	bool game_over(Pipe* down_pipe[], flip_pipe* up_pipe[]);
	bool fall();

	};

#endif