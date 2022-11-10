#include "Pipe.h"
#include <cstdlib>
#include "Functions.h"
#include "Data.h"
Pipe::Pipe()
{
	int ok = 0;
	int k = 0;
	n = 0;
	//srand(time(NULL));
	while (n < 11) {

	n = rand() % 17;
	}
	//n = 17;
	for (int i = n; i <=19; i++)
	{
		for (int j = 60; j <= 67; j++) {
			if (ok != 1) {
				SetColor(10);
				coordonate(j-1, i); std::cout << pipe[0][k];
			}
			else {
				SetColor(10);
				coordonate(j, i); std::cout << pipe[1][k];
			}
			k++;
		}
		k = 0;
		ok=1;
	}
	SetColor(15);
	x = 60;
}
bool Pipe::move_pipe() {
	x -= 1;

	SetColor(10);
	if (x > 2) {
		int ok = 0;
		int j;
		int k = 0;
		for (int i = n; i <= 19; i++)
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
		return false;
	}
	else
	{
		SetColor(15);
		//int j=2;
		for (int i = n; i <= 19; i++)
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

int Pipe::get_n()
{
	return n;
}
