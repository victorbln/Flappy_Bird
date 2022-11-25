#pragma once
class Pipe
{
	int m_head;//position of the head of the pipe on Y axis...generated random(see the constructor)
	int m_x;//position of the pipe on X axis...corresponding to the left side of it
public:
	Pipe();//constructor
	~Pipe();//destructor
	int m_get_head();//will return 
	int m_get_x();
	bool m_move_down_pipe();
};

///
///   |     |
///    |   |
///    |   |
///     
///