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
	int m_x;
	int m_y;
public:

	Bird();
	~Bird();
	int move_bird(char ch);
	bool game_over(Pipe* down_pipe[], flip_pipe* up_pipe[]);
	bool fall();

	};

#endif