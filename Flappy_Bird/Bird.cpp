#include "Bird.h"
#include <iostream>
#include <windows.h>
#include "Data.h"
#include "Functions.h"
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
Bird::Bird()
{
	SetColor(6);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 7; j++) {
			coordonate(10+j, 10+i);
			std::cout << bird[i][j];
		}
	}
	m_y1 = 10;
	m_y2 = 10;
	SetColor(15);
}


int Bird::move_bird(char ch) 
{
	SetColor(6);
	if (ch == 32)
	{
		if (m_y2 > 4)
		{
			m_y2 -= 1;
			ShowConsoleCursor(false);
			
			for (int i = 0; i < 2; i++) 
			{
				for (int j = 0; j < 7; j++) 
				{
					coordonate(m_y1 + j, m_y2 + i);
					std::cout << bird[i][j];
				}
			}
			coordonate(10, m_y2+2); std::cout << "       ";
			SetColor(15);
			return 1;
		}
		SetColor(15);
		return 0;
	}
	else
	{
		SetColor(15);
		return 1;
	}
}

bool Bird::fall() 
{
	ShowConsoleCursor(false);
	SetColor(6);
	if (m_y2 < 19) 
	{
	m_y2 += 1;
		for (int i = 0; i < 2; i++) 
		{
			for (int j = 0; j < 7; j++) 
			{
				coordonate(m_y1 + j, m_y2 + i);
				std::cout << bird[i][j];
			}
		}
		coordonate(10, m_y2 - 1); std::cout << "       ";
		return false;
	}
	else 
	{
		return true;
	}
}

bool Bird::game_over(Pipe* down_pipe[], flip_pipe* up_pipe[]) {

	if (m_y2 == 19) //bird hit the ground
	{
		return true;
	}
	for (int i = 0; i <= pipes; i++) 
	{
		if (m_y1 > up_pipe[i]->m_get_head() && m_y2 < down_pipe[i]->m_get_head()) //is bird between the heads of the pipes?
		{
			return false;
		}
		else
		{
			if (m_y1 + 7 == up_pipe[i]->m_get_x() || m_y1 + 7 == down_pipe[i]->m_get_x() || m_y2 + 5 == down_pipe[i]->m_get_x())
			{
				return true;
			}
		}
	}

	return false;

}
Bird::~Bird()
{
}
