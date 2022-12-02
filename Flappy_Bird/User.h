#ifndef USER_H
#define USER_H
#include <string>
#include <fstream>
#include <conio.h>

#include "console_handling.h"

class User : public console_handling
{private:
	short m_USERNAME_MAX_DIM;
	short m_USERNAME_MIN_DIM;
	short m_PASSWORD_MIN_DIM;
	short m_PASSWORD_MAX_DIM;

	std::string m_user_name;
	std::string m_password;
	int m_score;
	std::fstream database;



public:
	User();
	~User();
	std::string m_get_user_name();
	std::string m_get_password();
	int m_get_score();


	void m_set_login_string_dimensions(short username_min_dim, short username_max_dim, short password_min_dim, short password_max_dim);
	void m_set_score(int score);
	void m_set_user_name(char name);
	void m_set_password(char pass);


	int m_login_user();
	void m_register_user();
	void save_info();

private:



};





#endif