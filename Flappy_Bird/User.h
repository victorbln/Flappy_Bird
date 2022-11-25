#ifndef USER_H
#define USER_H
#include <string>
#include <fstream>

#include "Functions.h"
#include "Data.h"

class User
{private:
	std::string m_user_name;
	std::string m_password;
	long long m_score;
	//char* user_name_ = new char[15];
	char* user_name_;
	//char* password_ = new char[20];
	char* password_;

public:
	User();
	~User();
	std::string m_get_user_name();
	std::string m_get_password();
	long long m_get_score();
	void m_set_user_name(char name);
	void m_set_password(char pass);
	void m_set_score(long long score);
	bool m_login_user();
	void m_register_user();
	void check_user();
private:



};





#endif