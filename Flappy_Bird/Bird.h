#ifndef BIRD_H
#define BIRD_H
class Bird
{
	char m_bird[2][7];
	int y1;
	int y2;
public:

	Bird();
	~Bird();
	int move_bird(char ch);
	bool game_over();
	void update_pos();
	bool fall();
	void hit();
	};

#endif