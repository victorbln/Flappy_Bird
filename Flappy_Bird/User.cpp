#include <string>
#include <fstream>
#include <conio.h>

#include "User.h"
#include "Data.h"
#include "Functions.h"
User::User()
{
	m_USERNAME_MIN_DIM = 6;
	m_USERNAME_MAX_DIM = 20;
	m_PASSWORD_MIN_DIM = 8;
	m_PASSWORD_MAX_DIM = 24;
	m_score = 0;
}
void User::m_set_login_string_dimensions(short username_min_dim, short username_max_dim, short password_min_dim, short password_max_dim)
{
	m_USERNAME_MIN_DIM = username_min_dim;
	m_USERNAME_MAX_DIM = username_max_dim;
	m_PASSWORD_MIN_DIM = password_min_dim;
	m_PASSWORD_MAX_DIM = password_max_dim;
}

int User::m_login_user()
{
	bool QUIT_NAME=false;
	bool QUIT_PASS = false;
	bool SHOW_PASS = false;

	int USERNAME_DIM = 0;
	int PASSWORD_DIM = 0;

	User* u = new User();
	char* user_name_ = new char[m_USERNAME_MAX_DIM];
	char* password_ = new char[m_PASSWORD_MAX_DIM];
	char* ch = new char[1];;

	this->m_password.clear();
	this->m_user_name.clear();
	u->m_password.clear();
	u->m_user_name.clear();

	//display login screen
	chenar();
	ShowConsoleCursor(1);
	coordonate(32, 2); std::cout << "LOGIN MENIU";
	coordonate(25, 12);
	std::cout << "USERNAME: ";
	coordonate(25, 13);
	std::cout << "PASSWORD: ";
	coordonate(3, 18);
	std::cout << "The username must be at least "<< m_USERNAME_MIN_DIM <<" and maxim "<< m_USERNAME_MAX_DIM <<" characters";
	coordonate(3, 19);
	std::cout << "The password must be at least " << m_PASSWORD_MIN_DIM << " and maxim " << m_PASSWORD_MAX_DIM << " characters";
	SetColor(2);
	coordonate(10, 5); std::cout << "                    Press ESC to quit";
	coordonate(10, 6); std::cout << "        You can't insert blank spaces in the password";
	coordonate(7, 7); std::cout << "Press SPACE to show the password then press SPACE again to hide it";
	coordonate(35, 12);
	SetColor(15);


	//read username 
	while (!QUIT_NAME)
	{
		
		*ch = _getch();
		while (*ch != 13 || USERNAME_DIM < m_USERNAME_MIN_DIM)
		{
			if (*ch == 27)
			{
				QUIT_NAME = true;
				break;
			}
			if (*ch != 13)
			{
				if (USERNAME_DIM < m_USERNAME_MAX_DIM && *ch != 8)
				{
					coordonate(35 + USERNAME_DIM, 12);
					std::cout << *ch;
					user_name_[USERNAME_DIM] = *ch;
					USERNAME_DIM++;
				}
				else if (*ch == 8 && USERNAME_DIM != 0)
				{
					USERNAME_DIM--;
					coordonate(35 + USERNAME_DIM, 12);
					std::cout << " ";
					coordonate(35 + USERNAME_DIM, 12);
				}
			}
			*ch = _getch();
		}
		if (*ch == 13)
		{
			break;
			
		}
	}
	if (!QUIT_NAME)
	{
		SHOW_PASS = false;
		QUIT_PASS = false;
		for (int j = 0; j < USERNAME_DIM; j++)
		{
			this->m_user_name.push_back(user_name_[j]);
		}

		coordonate(35, 13);
		PASSWORD_DIM = 0;
		

		//read password 
		while (!QUIT_PASS)
		{
			*ch = _getch();
			if (*ch == 27)
			{
				QUIT_PASS = true;
				break;
			}
			
			while (*ch != 13 || PASSWORD_DIM < m_PASSWORD_MIN_DIM)//!=ENTER
			{
				if (*ch == 27)//*ch==ESC
				{
					QUIT_PASS = true;
					break;
				}

				if (*ch == 32)//*ch==SPACE
				{
					SHOW_PASS = !SHOW_PASS;
					coordonate(35, 13);
					if (SHOW_PASS)
					{
						for (int i = 0; i < PASSWORD_DIM; i++)
						{
							std::cout << password_[i];
						}
					}
					else
					{

						for (int i = 0; i < PASSWORD_DIM; i++)
						{
							std::cout << "*";
						}
					}
				}

				if (*ch != 13&&*ch!=32)
				{
					if (PASSWORD_DIM < m_PASSWORD_MAX_DIM && *ch != 8)
					{
						coordonate(35 + PASSWORD_DIM, 13);
						if (SHOW_PASS) 
						{
							std::cout << *ch;
						}
						else
						{
							std::cout << "*";
						}
						password_[PASSWORD_DIM] = *ch;
						PASSWORD_DIM++;
					}
					else if (*ch == 8 && PASSWORD_DIM != 0)
					{
						PASSWORD_DIM--;
						coordonate(35 + PASSWORD_DIM, 13);
						std::cout << " ";
						coordonate(35 + PASSWORD_DIM, 13);
					}
				}
				*ch = _getch();
			}
			if (*ch == 13)
			{
				break;
			}
		}
		if (!QUIT_PASS)
		{
			//SEARCHING FOR COMPATIBILITY
			for (int j = 0; j < PASSWORD_DIM; j++)
			{
				this->m_password.push_back(password_[j]);
			}
			database.close();
			database.open("database.bin", std::ios::binary | std::ios::in | std::ios::out);
			if (!database)
			{
				database.close();
				chenar();
				coordonate(10, 10);
				SetColor(4);
				std::cout << "Error at opening database.";
				coordonate(10, 15); system("PAUSE");
			}
			else
			{
				database.seekp(0, std::ios_base::beg);
				while (1)
				{
					u->m_password.clear();
					u->m_user_name.clear();
					u->m_score = 0;
					if (database.eof())
					{
						return 1;
					}
					database >> u->m_user_name;
					database >> u->m_password;
					database >> u->m_score;

					if (!(u->m_user_name.compare(this->m_user_name)))
					{
						if (u->m_password == this->m_password)
						{
							this->m_score = u->m_score;
							return 0;
						}
					}
					
				}
			}
		}
	}

	database.close();
	delete u;
	delete[] ch;
	delete[] user_name_;
	delete[] password_;
	return -1;
}



void User::m_register_user()
{
	bool QUIT_NAME = false;
	bool QUIT_PASS = false;
	bool SHOW_PASS = false;
	bool IS_UNIQUE = true;

	User* u = new User();
	char* user_name_ = new char[m_USERNAME_MAX_DIM];
	char* password_ = new char[m_PASSWORD_MAX_DIM];
	char *ch;
	int USERNAME_DIM = 0;
	int PASSWORD_DIM = 0;

	




	//from here starts the actual functionality of the method
	ch = new char[1];
	while (!QUIT_NAME)
	{
		//these lines are used to display a screen for registration
		m_user_name.clear();
		m_password.clear();
		delete[] user_name_;
		user_name_ = new char[m_USERNAME_MAX_DIM];
		chenar();
		ShowConsoleCursor(1);
		coordonate(30, 2); std::cout << "REGISTRATION MENIU";
		coordonate(25, 12);
		std::cout << "USERNAME: ";
		coordonate(25, 13);
		std::cout << "PASSWORD: ";

		coordonate(3, 18);
		std::cout << "The username must be at least " << m_USERNAME_MIN_DIM << " and maxim " << m_USERNAME_MAX_DIM << " characters";
		coordonate(3, 19);
		std::cout << "The password must be at least " << m_PASSWORD_MIN_DIM << " and maxim " << m_PASSWORD_MAX_DIM << " characters";

		coordonate(10, 5); std::cout << "                    Press ESC to quit";
		coordonate(10, 6); std::cout << "        You can't insert blank spaces in the password";
		coordonate(7, 7); std::cout << "Press SPACE to show the password then press SPACE again to hide it";
		coordonate(35, 12);
		coordonate(20, 9); std::cout << "                                                   ";
		coordonate(20, 10); std::cout << "                                                   ";


		//reading username
		coordonate(35, 12);
		IS_UNIQUE = true;
		*ch = _getch();
		while (*ch != 13 || USERNAME_DIM < m_USERNAME_MIN_DIM)
		{
			if (*ch == 27)
			{
				QUIT_NAME = true;
				break;
			}
			if (*ch != 13)
			{
				if (USERNAME_DIM < m_USERNAME_MAX_DIM && *ch != 8)
				{
					coordonate(35 + USERNAME_DIM, 12);
					std::cout << *ch;
					user_name_[USERNAME_DIM] = *ch;
					USERNAME_DIM++;
				}
				else if (*ch == 8 && USERNAME_DIM != 0)
				{
					USERNAME_DIM--;
					coordonate(35 + USERNAME_DIM, 12);
					std::cout << " ";
					coordonate(35 + USERNAME_DIM, 12);
				}
			}

			*ch = _getch();
		}
		if (*ch == 13)
		{
			//check if the username is already used
			for (int j = 0; j < USERNAME_DIM; j++)
			{
				this->m_user_name.push_back(user_name_[j]);
			}
			database.close();
			database.open("database.bin", std::ios::binary | std::ios::in | std::ios::out);
			if (!database)
			{
				database.close();
				chenar();
				coordonate(10, 10);
				SetColor(4);
				std::cout << "Error at opening database.";
				coordonate(10, 15); system("PAUSE");
			}
			else
			{
				database.seekp(0, std::ios_base::beg);
				while (IS_UNIQUE)
				{
					u->m_password.clear();
					u->m_user_name.clear();
					u->m_score = 0;
					if (database.eof())
					{
						//no matching username found
						IS_UNIQUE = true;
						break;
					}
					database >> u->m_user_name;
					database >> u->m_password;
					database >> u->m_score;

					if (!(u->m_user_name.compare(this->m_user_name)))
					{
						coordonate(20, 9); std::cout << "Username already used! Please type an unique one!";
						coordonate(20, 10); system("PAUSE");
						IS_UNIQUE = false;
						USERNAME_DIM = 0;

					}
					
				}
			}
			database.close();

			if (IS_UNIQUE)
			{
				//if the username is not used we leave this while loop
				break;
			}
		}
	}

	//if no quit ocurred when the user wrote the username we go on reading the password
	if (!QUIT_NAME)
	{
		QUIT_PASS = false;
		SHOW_PASS = false;
		this->m_user_name.clear();

		//saving the username in the string member m_user_name 
		for (int j = 0; j < USERNAME_DIM; j++)
		{
			m_user_name.push_back(user_name_[j]);
		}

		
		coordonate(35, 13);
		PASSWORD_DIM = 0;
		while (!QUIT_PASS)
		{
			*ch = _getch();
			while (*ch != 13 || PASSWORD_DIM < m_PASSWORD_MIN_DIM)
			{
				if (*ch == 27)
				{
					QUIT_PASS = true;
					break;
				}
				if (*ch == 32)
				{
					SHOW_PASS = !SHOW_PASS;
					coordonate(35, 13);
					if (SHOW_PASS)
					{
						for (int i = 0; i < PASSWORD_DIM; i++)
						{
							std::cout << password_[i];
						}
					}
					else
					{

						for (int i = 0; i < PASSWORD_DIM; i++)
						{
							std::cout << "*";
						}
					}
				}
				if (*ch != 13&&*ch!=32)
				{
					if (PASSWORD_DIM < m_PASSWORD_MAX_DIM && *ch != 8)
					{
						coordonate(35 + PASSWORD_DIM, 13);
						if (SHOW_PASS)
						{
							std::cout << *ch;
						}
						else
						{
							std::cout << "*";
						}
						password_[PASSWORD_DIM] = *ch;
						PASSWORD_DIM++;
					}
					else if (*ch == 8  && PASSWORD_DIM != 0)
					{
						PASSWORD_DIM--;
						coordonate(35 + PASSWORD_DIM, 13);
						std::cout << " ";
						coordonate(35 + PASSWORD_DIM, 13);
					}
				}
				*ch = _getch();
			}
			if (*ch == 13)
			{
				break;
			}
		}
		//if no quit has occured we save the informations for the user
		if (!QUIT_PASS)
		{
			database.close();
			database.open("database.bin", std::ios::binary | std::ios::out | std::ios::app);
			if (!database)
			{
				chenar();
				coordonate(10, 14); std::cout << "erorr at saving user";
				coordonate(10, 15); system("PAUSE");
			}
			else
			{
				for (int j = 0; j < USERNAME_DIM; j++)
				{
					database << user_name_[j];
				}
				database << std::endl;

			}
			database.close();


			for (int j = 0; j < PASSWORD_DIM; j++)
			{
				m_password.push_back(password_[j]);
			}

			database.open("database.bin", std::ios::binary | std::ios::out | std::ios::app);
			if (!database)
			{
				chenar();
				coordonate(10, 14); std::cout << "erorr at saving user";
				coordonate(10, 15); system("PAUSE");
			}
			else
			{
				for (int j = 0; j < PASSWORD_DIM; j++)
				{
					database << password_[j];
				}
				database << std::endl;
			}

			database << score << std::endl;
		}
	}
	database.close();
	delete[] ch;
	delete[] user_name_;
	delete[] password_;
	delete u;
}

void User::save_info()
{
	std::string str;
	User* u = new User;

	database.close();
	database.open("database.bin", std::ios::binary | std::ios::in | std::ios::out);
	if (!database)
	{
		database.close();
		chenar();
		coordonate(10, 10);
		SetColor(4);
		std::cout << "Error at opening database.";
		coordonate(10, 15); system("PAUSE");
	}
	else
	{
		while (1)
		{
			
			u->m_password.clear();
			u->m_user_name.clear();
			u->m_score = 0;
			if (database.eof())
			{
				break;
			}
			database >> u->m_user_name;
			database >> u->m_password;
			database >> str;
			
			
			int size =(int)str.size();
			if (!(u->m_user_name.compare(this->m_user_name)))//when we find the user data location we update the score
			{
				database.seekp(-size, std::ios::cur);
				database << this->m_score << std::endl;
			}
				
			if (database.eof())
			{
				break;
			}
		}
	}
	database.close();
	delete u;
}




User::~User()
{
}

std::string User::m_get_user_name()
{
	return m_user_name;
}

std::string User::m_get_password()
{
	return m_password;
}
int User::m_get_score()
{
	return m_score;
}

void User::m_set_user_name(char name)
{
	m_user_name = name;
}

void User::m_set_password(char pass)
{
	m_password = pass;
}

void User::m_set_score(int score)
{
	m_score = score;
}


