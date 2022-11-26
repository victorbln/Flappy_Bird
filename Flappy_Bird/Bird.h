#ifndef BIRD_H
#define BIRD_H
#include "Pipe.h"
#include "flip_pipe.h"
class Bird
{

	const char bird[2][7] = { ' ',' ','(',' ','o',')','>',
						' ','<','"','_','/',' ',' ' };//bird body array
	//char bird[2][7] = {  ( o)>
	  //                  <"_/   }
	//char m_bird[2][7];//body of the bird
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