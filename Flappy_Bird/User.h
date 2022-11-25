#ifndef USER_H
#define USER_H
#include <string>
#include <fstream>

#include "Functions.h"
#include "Data.h"

class User
{private:
	short m_USERNAME_MAX_DIM;
	short m_USERNAME_MIN_DIM;
	short m_PASSWORD_MIN_DIM;
	short m_PASSWORD_MAX_DIM;

	std::string m_user_name;
	std::string m_password;
	long long m_score;


public:
	User();
	~User();
	std::string m_get_user_name();
	std::string m_get_password();
	long long m_get_score();

	void m_set_score(long long score);
	void m_set_user_name(char name);
	void m_set_password(char pass);
	void m_set_login_string_dimensions(short username_min_dim,  short username_max_dim, short password_min_dim, short password_max_dim);

	int m_login_user();
	void m_register_user();

private:



};





#endif