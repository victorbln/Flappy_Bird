#ifndef BIRD_H
#define BIRD_H
#include "Pipe.h"
#include "flip_pipe.h"
class Bird
{
	//char m_bird[2][7];//body of the bird
	int m_y1;
	int m_y2;
public:

	Bird();
	~Bird();
	int move_bird(char ch);
	bool game_over(Pipe* down_pipe[], flip_pipe* up_pipe[]);
	bool fall();

	};

#endif