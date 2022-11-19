#include "Pipe.h"
#include <cstdlib>
#include "Functions.h"
#include "Data.h"
Pipe::Pipe()
{
	int ok = 0;
	int k = 0;
	m_head = 0;

	//generating a random value for the head of the pipe
	//its value needs to be greater than 12 because we need to create another pipe 
	//on the up side and we also have a gap between them
	while (m_head < 11) 
	{
		m_head = rand() % 17;
	}
	
	SetColor(10);//setting the console text to green
	//display the pipe on the console
	for (int i = m_head; i <=19; i++)
	{
		for (int j = 60; j <= 67; j++) 
		{
			if (ok != 1) 
			{
				coordonate(j-1, i); std::cout << pipe[0][k];
			}
			else 
			{
				coordonate(j, i); std::cout << pipe[1][k];
			}
			k++;
		}
		k = 0;
		ok=1;
	}

	m_x = 60;//default position for the m_x member is 60 because there is the pipe created on the screen
}
bool Pipe::m_move_down_pipe() {
	m_x -= 1;//decrement the m_x member is a move to left for the pipe

	SetColor(10);
	if (m_x > 2) {
		int ok = 0;
		int j;
		int k = 0;
		for (int i = m_head; i <= 19; i++)
		{
			for (j = m_x; j <= m_x + 7; j++) {
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
	else//if the m_x = 2 that means that the pipe is at the left edge of the window so we erase it from the screen 
	{
		for (int i = m_head; i <= 19; i++)
		{
			for (int j=2 ; j <= 10; j++) 
			{
				coordonate(j, i); std::cout << " ";
			}
		}
		return true;
	}
}

Pipe::~Pipe()
{
}

int Pipe::m_get_head()
{
	return m_head;
}

int Pipe::m_get_x()
{
	return m_x;
}
