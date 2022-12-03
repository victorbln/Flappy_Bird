#ifndef PIPE_H
#define PIPE_H

#include <cstdlib>
#include "console_handling.h"

class Pipe : public console_handling
{
	const char pipe[2][8] = { '\xDB','\xDB','\xDB','\xDB','\xDB','\xDB','\xDB',//head of the pipe
					  ' ','\xDB','\xDB','\xDB','\xDB','\xDB',' ' };//body of the pipe
///       |     |
///        |   |
///        |   |
///        |   |  

	int m_head;//position of the head of the pipe on Y axis...generated random(see the constructor)
	int m_x;//position of the pipe on X axis...corresponding to the left side of it
public:
	Pipe();
	~Pipe();
	int m_get_head();//returns the y coordinate of the head of the pipe
	int m_get_x();//returns the x coordinate of the pipe
	bool m_move_down_pipe();//method that moves the pipe 1 space
};

#endif