#include "User.h"
#include "Data.h"
User::User()
{
	user_name_ = new char[15];
	password_ = new char[20];
}


bool User::m_login_user()
{
	this->m_password.clear();
	this->m_user_name.clear();
	User* u = new User();
	char ch;
	u->m_password.clear();
	u->m_user_name.clear();
	chenar();
	ShowConsoleCursor(1);

	coordonate(25, 10);
	std::cout << "USERNAME: ";
	coordonate(25, 11);
	std::cout << "PASSWORD: ";
	coordonate(35, 10);


	int i = 0;
	
	ch = (char)"";
	ch = _getch();
	while (ch != 13 || i<=5)
	{
		if (ch != 13)
		{
			if (i < 10 && ch != 8)
			{
				coordonate(35 + i, 10);
				std::cout << ch;
				this->user_name_[i] = ch;
				i++;
			}
			else if (i >= 10 && ch == 8)
			{
				i--;
				coordonate(35 + i, 10);
				std::cout << " ";
				coordonate(35 + i, 10);
			}
			else if (ch == 8 && i <= 10 && i != 0)
			{
				i--;
				coordonate(35 + i, 10);
				std::cout << " ";
				coordonate(35 + i, 10);
			}
		}
		ch = _getch();
	}
	for (int j = 0; j < i; j++)
	{
		this->m_user_name.push_back(this->user_name_[j]);
	}
	coordonate(35, 11);
	

	i = 0;
	ch = (char)"";
	ch = _getch();
	while (ch != 13 || i<=5 )
	{
		if (ch != 13)
		{
			if (i < 10 && ch != 8)
			{
				coordonate(35 + i, 11);
				std::cout << ch;
				this->password_[i] = ch;
				i++;
			}
			else if (i >= 10 && ch == 8)
			{
				i--;
				coordonate(35 + i, 11);
				std::cout << " ";
				coordonate(35 + i, 11);
			}
			else if (ch == 8 && i <= 10 && i != 0)
			{
				i--;
				coordonate(35 + i, 11);
				std::cout << " ";
				coordonate(35 + i, 11);
			}
		}
		ch = _getch();
	}
	for (int j = 0; j < i; j++)
	{
		this->m_password.push_back(this->password_[j]);
	}
	database.close();
	database.open("database.bin", std::ios::binary|std::ios::in|std::ios::out);
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



		u->m_password.clear();
		u->m_user_name.clear();
		database.seekp(0, std::ios_base::beg);

		while (1)
		{
			u->m_password.clear();
			u->m_user_name.clear();
			u->m_score=0;
			database >> u->m_user_name;
			database >> u->m_password;
			database >> u->m_score;
			for (int i = 27; i <= 41; i++)
			{
				coordonate(0, i); std::cout << "                                                                                                                            ";
			}
			if (!(u->m_user_name.compare(this->m_user_name)))
			{
				if (u->m_password == this->m_password)
				{
					this->m_score = u->m_score;
					return true;
				}
			}
			else
			{
				u->m_password.clear();
				u->m_user_name.clear();
			}
			if(database.eof())
			{
				return false;
			}
		}
	}
	database.close();
	delete u;
	return false;
}

void User::m_register_user()
{
	char ch;
	//char name[50];
	//char pass[50];
	std::string str;

	chenar();
	ShowConsoleCursor(1);

	coordonate(25, 10);
	std::cout << "USERNAME: ";
	coordonate(25, 11);
	std::cout << "PASSWORD: ";
	coordonate(35, 10);

	//str = "";
	int i = 0;
	ch = (char)"";
	ch = _getch();
	while (ch != 13||i<=5)
	{
		//if (str.size() < 10 && ch != 8)
		if (ch != 13)
		{
			if (i < 10 && ch != 8)
			{
				//coordonate(35 + str.size(), 10);
				coordonate(35 + i, 10);
				std::cout << ch;
				//str.push_back(ch);
				user_name_[i] = ch;
				i++;
			}
			//else if (str.size() >= 10 && ch == 8)
			else if (i >= 10 && ch == 8)
			{
				//str.pop_back();
				i--;
				//coordonate(35 + str.size(), 10);
				coordonate(35 + i, 10);
				std::cout << " ";
				//coordonate(35 + str.size(), 10);
				coordonate(35 + i, 10);
			}
			//else if (ch == 8 && i <= 10 && i != 0)
			else if (ch == 8 && str.size() <= 10 && i != 0)
			{
				//str.pop_back();
				i--;
				//coordonate(35 + str.size(), 10);
				coordonate(35 + i, 10);
				std::cout << " ";
				//coordonate(35 + str.size(), 10);
				coordonate(35 + i, 10);
			}
		}
		ch = _getch();
	}
	//m_user_name = str;
	user_name_[i + 1] = (char)"\0";
	for (int j = 0; j < i; j++)
	{
		m_user_name.push_back(user_name_[j]);
	}
	m_user_name = user_name_;
	//strcpy_s(m_user_name, str.c_str());


	//std::fstream database;
	database.open("database.bin", std::ios::binary | std::ios::out | std::ios::app);
	if (!database)
	{
		chenar();
		coordonate(10, 14); std::cout << "erorr at saving user";
		coordonate(10, 15); system("PAUSE");
	}
	else
	{
		for (int j = 0; j < i; j++)
		{
			database << user_name_[j];
		}
		database << std::endl;

	}
	database.close();



	
	coordonate(35, 11);
	i = 0;
	//str = "";
	ch = (char)"";
	ch = _getch();
	//while (ch != 13 || str == "")
	while (ch != 13 || i<=5)
	{
		//if (str.size() < 10 && ch != 8)
		if (ch != 13)
		{
			//if (str.size() < 10 && ch != 8)
			if (i < 10 && ch != 8)
			{
				//coordonate(35 + str.size(), 11);
				coordonate(35 + i, 11);
				std::cout << ch;
				//str.push_back(ch);
				password_[i] = ch;
				i++;
			}
			//else if (str.size() >= 10 && ch == 8)
			else if (i >= 10 && ch == 8)
			{
				//str.pop_back();
				i--;
				//coordonate(35 + str.size(), 11);
				coordonate(35 + i, 11);
				std::cout << " ";
				//coordonate(35 + str.size(), 11);
				coordonate(35 + i, 11);
			}
			//else if (ch == 8 && str.size() <= 10 && str.size() != 0)
			else if (ch == 8 && i <= 10 && i != 0)
			{
				//str.pop_back();
				i--;
				//coordonate(35 + str.size(), 11);
				coordonate(35 + i, 11);
				std::cout << " ";
				//coordonate(35 + str.size(), 11);
				coordonate(35 + i, 11);
			}
		}
		ch = _getch();
	}
	password_[i + 1] = (char)"\0";
	for (int j = 0; j < i; j++)
	{
		m_password.push_back(password_[j]);
	}
	 //m_password= str;
	//std::fstream database;
	database.open("database.bin", std::ios::binary | std::ios::out | std::ios::app);
	if (!database)
	{
		chenar();
		coordonate(10, 14); std::cout << "erorr at saving user";
		coordonate(10, 15); system("PAUSE");
	}
	else
	{
		for (int j = 0; j < i; j++)
		{
			database << password_[j];
		}
		database << std::endl;
	}
	database << score << std::endl;
	database.close();

}

void User::check_user()
{
	User* u=new User();
	std::fstream database;
	database.open("database.bin", std::ios::binary | std::ios::in);
	if (!database)
	{
		database.close();
		chenar();
		coordonate(10, 10);
		SetColor(4);
		std::cout << "Error at opening database.";
	}
	else
	{
		database.seekp(0, std::ios_base::beg);
		//while(database.read((char*)u, sizeof(User)))
		while(database.getline((char*)u, sizeof(User)))
		{
			coordonate(10, 16);
			std::cout << u->m_user_name << " " << u->m_password;
			coordonate(10, 17);
			std::cout << m_user_name << " " << m_password;
			if (u->m_user_name == m_user_name)
			{
				if (u->m_password == m_password)
				{
					acces = 1;
				}
			}
			else
			{
				acces = 0;
			}
			//database.getline((char*)u,sizeof(User))
			//database.seekp(database.tellg()+1);
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

long long User::m_get_score()
{
	return m_score;
}

void User::m_set_user_name(char name)
{
	m_user_name[30] = name;
}

void User::m_set_password(char pass)
{
	m_password[30] = pass;
}

void User::m_set_score(long long score)
{
	m_score = score;
}