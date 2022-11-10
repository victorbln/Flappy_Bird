#include "flip_pipe.h"
#include <cstdlib>
#include "Functions.h"
#include "Data.h"

flip_pipe::flip_pipe()
{

}
void flip_pipe::create(int a) {
	int ok = 0;
	int k = 0;
	SetColor(10);
	n = a-6;
	for (int i =n; i >= 4; i--)
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
	x = 60;

}
flip_pipe::~flip_pipe()
{
}
bool flip_pipe::flip_pipe_move()
{
	SetColor(10);
	x -= 1;
	if (x > 2) {
		int ok = 0;
		int j;
		int k = 0;
		for (int i = n; i >= 4; i--)
		{
			for (j = x; j <= x + 7; j++) {
				if (ok != 1) {
					coordonate(j - 1, i); std::cout << pipe[0][k];
				}
				else {
					coordonate(j, i); std::cout << pipe[1][k];
				}
				k++;
			}
			coordonate(j + 1, i); std::cout << " ";
			k = 0;
			ok = 1;
		}
	SetColor(15);
	return false;
	}
	else
	{
		SetColor(15);
		for (int i = n; i >=4; i--)
		{
			for (int j=2; j <= 10; j++) 
			{
				coordonate(j, i); std::cout << "  ";
			}
		}
		return true;
	}
}
void flip_pipe::set_n(int a) {
	n = a;
}