#pragma once
class flip_pipe
{
	//char m_pipe[2][8];
	int n;
	int x;
public:
	flip_pipe();
	~flip_pipe();
	bool flip_pipe_move();
	void create(int a);
	void set_n(int a);
};

