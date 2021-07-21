#include "USocial.h"
#include "User.h"
#include "BusinessUser.h"

#define FIRST_ID 1111

USocial::USocial() 
{
    next_id = FIRST_ID;
}

USocial::~USocial()
{
    for (auto user : users)
    {
        delete user.second;//selete all the pointers of the users
    }
}


User* USocial::registerUser(std::string user_name, bool business)
{
    if (!user_name.empty())
    {
        User* user;
        if (business)
        {
            user = new BusinessUser(next_id, user_name, this);
        }
        else
        {
            user = new User(next_id, user_name, this);
        }

        users.insert({ next_id, user });//adding the new friend to the end
        next_id++;
        return user;
    }
    else
    {
        std::string error_message = "\n*** the given name is empty or null ***\n";
        throw std::invalid_argument(error_message);
    }
}

User* USocial::registerUser(std::string user_name)
{
    return registerUser(user_name, false);
}



bool USocial::isRegistered(User* user)
{
    if (user)
    {
        unsigned long u_id = user->getId();
        User* user = users[u_id];
        if (user)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        std::string error_message = "\n*** the given user is null ***\n";
        throw std::invalid_argument(error_message);
    }
}

void USocial::removeUser(User* user)
{
    if (user)
    {
        if (isRegistered(user))
        {
            unsigned long user_id = user->getId();
            users.erase(user_id);
            std::cout <<"\n" << user->getName() << " removerd.\n" << std::endl;
            delete user;
        }
        else
        {
            std::string error_message = "\n*** the given user is not registered ***\n";
            throw std::invalid_argument(error_message);
        }
    }
    else
    {
        std::string error_message = "\n*** the given user is null ***\n";
        throw std::invalid_argument(error_message);
    }
}


User* USocial::getUserById(unsigned long needed_id)
{
    User* user = users[needed_id];
    if (user)
    {
        return user;
    }
    else
    {
        std::string error_message = "\n*** the given is not from a registered user ***\n";
        throw std::invalid_argument(error_message);
    }
}
