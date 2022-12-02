#ifndef FLIP_PIPE_H
#define FLIP_PIPE_H
#include "console_handling.h"
class flip_pipe : public console_handling
{
	const char pipe[2][8] = { '\xDB','\xDB','\xDB','\xDB','\xDB','\xDB','\xDB',//head of the pipe
					  ' ','\xDB','\xDB','\xDB','\xDB','\xDB',' ' };//body of the pipe
	int m_head;
	int m_x;
	int gap = 6;//gap between pipes
public:
	flip_pipe(int down_pipe_head_value = 0);
	~flip_pipe();
	int m_get_head();
	int m_get_x();
	bool m_move_flip_pipe();


};

#endif