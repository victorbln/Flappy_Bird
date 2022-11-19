#include "flip_pipe.h"
#include <cstdlib>
#include "Functions.h"
#include "Data.h"

flip_pipe::flip_pipe(int down_pipe_head_value)//we need the down_pipe_head_value to create the up side pipe 
//with a gap between it and the down side pipe
{
	int ok = 0;
	int k = 0;
	m_head = down_pipe_head_value - gap;//we will create the up side pipe at a Y position which is down_pipe_head_value - gap

	SetColor(10);
	//display the pipe on the console
	for (int i =m_head; i >= 4; i--)
	{
		for (int j = 60; j <= 67; j++) {
			if (ok != 1) {
				coordonate(j-1, i); std::cout << pipe[0][k];
			}
			else {

				coordonate(j, i); std::cout << pipe[1][k];
			}
			k++;
		}
		k = 0;
		ok = 1;
	}
	m_x = 60;//default position for the m_x member is 60 because there is the pipe created on the screen

}
bool flip_pipe::m_move_flip_pipe()
{
	SetColor(10);//setting the color to green
	m_x -= 1;//decrement the m_x member is a move to left for the pipe
	if (m_x > 2) 
	{	//not at the edge of the window
		int ok = 0;
		int j;
		int k = 0;
		for (int i = m_head; i >= 4; i--)
		{
			for (j = m_x; j <= m_x + 7; j++) 
			{
				if (ok != 1) 
				{	
					//at first iteration we are creating the head of the pipe (pipe[0][k])
					coordonate(j - 1, i); std::cout << pipe[0][k];
				}
				else 
				{
					//for the rest of them we are creating the body of it (pipe[1][k])
					coordonate(j, i); std::cout << pipe[1][k];
				}
				k++;
			}
			coordonate(j + 1, i); std::cout << " ";
			k = 0;
			ok = 1;
		}
	return false;//return false if the pipe is not at the edge of thw window
	}
	else
	{	//if the m_x = 2 that means that the pipe is at the left edge of the window so we erase it from the screen 
		for (int i = m_head; i >=4; i--)
		{
			for (int j=2; j <= 10; j++) 
			{
				coordonate(j, i); std::cout << "  ";
			}
		}
		return true;//return true if the pipe is at the edge of the window
	}
}


flip_pipe::~flip_pipe()
{
}

int flip_pipe::m_get_head()
{
	return m_head;
}

int flip_pipe::m_get_x()
{
	return m_x;
}
