#pragma once
#include <map>
#include "User.h"
#include <string>

class USocial
{
	friend class User;
private:
	std:: map<unsigned long, User*> users;
	unsigned long next_id;
public:
	USocial();
	~USocial();
	User* registerUser(std::string, bool);
	User* registerUser(std::string);
	void removeUser(User*);
	User* getUserById(unsigned long);
	bool isRegistered(User*);
};

