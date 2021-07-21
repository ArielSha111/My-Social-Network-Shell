#pragma once
#include "User.h"
class BusinessUser :
    public User
{
public:
    ~BusinessUser();
    BusinessUser(int, std::string,USocial*);
    void sendMessage(User*, Message*);
};

