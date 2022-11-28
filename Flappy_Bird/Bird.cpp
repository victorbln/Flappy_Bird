#include <iostream>
#include <windows.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>

#include "Data.h"
#include "Functions.h"
Bird::Bird()
{
	SetColor(6);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 7; j++) {
			coordonate(10+j, 10+i);
			std::cout << bird[i][j];
		}
	}
	m_x = 10;
	m_y = 10;
	SetColor(15);
}


void Bird::move_bird(char ch) 
{
	ShowConsoleCursor(false);
	SetColor(6);

	if (ch == 32)//32=space key
	{
		//jump only if the bird is bellow the top side of the window
		if (m_y > 4)
		{
			//update position
			m_y -= 1;

			//printing the bird with the updated position
			for (int i = 0; i < 2; i++) 
			{
				for (int j = 0; j < 7; j++) 
				{
					coordonate(m_x + j, m_y + i);
					std::cout << bird[i][j];
				}
			}

			//erasing the row bellow the bird
			coordonate(10, m_y+2); std::cout << "       ";
			SetColor(15);
		}
	}

}

bool Bird::fall() 
{
	ShowConsoleCursor(false);
	SetColor(6);

	if (m_y < 18) 
	{
		//updating the y position of the bird
		m_y += 1;

		//printing the bird
		for (int i = 0; i < 2; i++) 
		{
			for (int j = 0; j < 7; j++) 
			{
				
				coordonate(m_x + j, m_y+ i);
				std::cout << bird[i][j];

			}
		}
		//errasing the row above the bird
		coordonate(10, m_y - 1); std::cout << "        ";
		return false;
	}
	return true;
}

bool Bird::game_over(Pipe* down_pipe[], flip_pipe* up_pipe[]) 
{
	//collision with the pipe from bottom side
	if (down_pipe[0]->m_get_x() + 5 >= m_x && m_y+1 >= down_pipe[0]->m_get_head())
	{
		if (  m_x + 8 >= down_pipe[0]->m_get_x())
		{
			return true;
		}
	}

	//collision with the pipe from top side
	if (up_pipe[0]->m_get_x() + 5 >= m_x && m_y <= up_pipe[0]->m_get_head())
	{
		if (  m_x + 8 >= up_pipe[0]->m_get_x())
		{
			return true;
		}
	}	
	return false;

}
Bird::~Bird()
{
}
