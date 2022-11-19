#pragma once
class flip_pipe
{

	int m_head;
	int m_x;
public:
	flip_pipe(int down_pipe_head_value = 0);
	~flip_pipe();
	int m_get_head();
	int m_get_x();
	bool m_move_flip_pipe();


};

