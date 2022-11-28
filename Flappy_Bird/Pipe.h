#pragma once
class Pipe
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
	int m_get_head();
	int m_get_x();
	bool m_move_down_pipe();
};