#include "User.h"
#include "Post.h"
#include <list>
#include <iostream>


User::User()
{
    id = 0;
    name = "";

}

User::User(int needed_id, std::string needed_name,USocial* us)
{
    id = needed_id;
    name = needed_name;
    _us = us;
}

User::~User()
{
    for (auto post : posts)
    {
        delete post;
    }
    for (auto message : receivedMsgs)
    {
        delete message;
    }
}


long User::getId() 
{
    return id;
}

std::string User::getName()
{
    return name;
}


void User::addFriendFromOutside(User* user)
{
    if (user)
    {
        int f_id = user->getId();
        friends.push_back(f_id);//adding the new friend to the end
    }
    else
    {
        std::string error_message = "\n*** user to add in null ***\n";
        throw std::invalid_argument(error_message);
    }
}



void User::addFriend(User* user)
{
    if (user)
    {
        int f_id = user->getId();
        friends.push_back(f_id);//adding the new friend to the end
        user->addFriendFromOutside(this);
    }
    else
    {
        std::string error_message = "\n*** user to add in null ***\n";
        throw std::invalid_argument(error_message);
    }
}


void User::removeFriendFromOutside(User* user)
{
    if (user)
    {
        if (isMyFriend(user))
        {
            int f_id = user->getId();
            friends.remove(f_id);
        }
        else
        {
            std::string error_message = "\n*** user to remove is not a friend of: " + name + " ***\n";
            throw std::invalid_argument(error_message);
        }
    }
    else
    {
        std::string error_message = "\n*** user to remove in null ***\n";
        throw std::invalid_argument(error_message);
    }

}


void User::removeFriend(User* user)
{
    if (user)
    {
        if (isMyFriend(user))
        {
            int f_id = user->getId();
            friends.remove(f_id);
            user->removeFriendFromOutside(this);
        }
        else
        {
            std::string error_message = "\n*** user to remove is not a friend of: " + name + " ***\n";
            throw std::invalid_argument(error_message);
        }
    }
    else
    {
        std::string error_message = "\n*** user to remove in null ***\n";
        throw std::invalid_argument(error_message);
    }
   
}

void User::post(std::string str)
{
    if(!str.empty())
    {
        Post* post = new Post(str);
        posts.push_back(post);//adding the new post to the end
    }
    else
    {
        std::string error_message = "\n*** the post string is null or empty ***\n";
        throw std::invalid_argument(error_message);
    }
}

void User::post(std::string str, Media* m)
{
    if (!str.empty())
    {
        if (m)
        {
            Post* post = new Post(str, m);
            posts.push_back(post);//adding the new post to the end
        }
        else
        {
            std::string error_message = "\n*** the given media is null ***\n";
            throw std::invalid_argument(error_message);
        }

    }
    else
    {
        std::string error_message = "\n*** the post string is null or empty ***\n";
        throw std::invalid_argument(error_message);
    }
}

std::list<Post*> User::getPosts()
{
    return posts;
}

void User::viewAllPosts()
{
    std::cout << "posts by: " << name << std::endl;
    int counter = 1;
    for (auto post : posts)
    {
        std::cout << std::endl;
        std::cout << "\tpost number " << counter << " is: " << std::endl;
        post->display();
        counter++;
    }
    std::cout << std::endl;
    std::cout <<"thats all " << name<<" posts."<< std::endl;
    std::cout << std::endl<<std::endl;
}

void User::viewFriendsPosts()
{
    std::cout << "all the friends posts of: " << name << std::endl;
    std::cout << std::endl;
    for (auto friend_id : friends)
    {      
        User* cur_friend = _us->getUserById(friend_id);      
        cur_friend->viewAllPosts();
    }
    std::cout << "thats all " << name << " friends posts." << std::endl;
    std::cout << std::endl << std::endl;
}

void User::receiveMessage(Message* m)
{
    if (m)
    {
        receivedMsgs.push_back(m);//adding the new message to the end
    }
    else
    {
        std::string error_message = "\n*** this message is null ***\n";
        throw std::invalid_argument(error_message);
    }

}


bool User::isMyFriend(User* u)
{
    for (auto friend_id : friends)
    {
        if (u->getId()== friend_id)
        {
            return true;
        }
    }
    return false;
}

void User::sendMessage(User* u, Message* m )
{
    if (u)
    {
        if (isMyFriend(u))
        {
            if (m)
            {
                u->receiveMessage(m);
            }
            else
            {
                std::string error_message = "\n*** the given message is null ***\n";
                throw std::invalid_argument(error_message);
            }
        } 
        else
        {
            std::string error_message = "\n*** " + u->getName() + " is not a friend of " + name + " ***\n";
            throw std::invalid_argument(error_message);
        }
    }
    else
    {
        throw std::invalid_argument("the given user  is null");
    }

}

void User::viewReceivedMessages()
{
    int counter = 1;
    std::cout << "all of " << name << " messages are: " << std::endl<<std::endl;
    for (auto msg : receivedMsgs)
    {
        std::cout <<"\tmessage number " <<counter<<" is: " << std::endl;
        std::cout <<"\t\t" << (msg->getText()) << std::endl;
        std::cout << std::endl;
        counter++;
    }
    std::cout << "thats all of " << name << " messages." << std::endl << std::endl << std::endl;
}

void User::viewAllFriends()
{
    std::cout << "all the friends of: " << name <<" are:" << std::endl;
    std::cout << std::endl;
    std::string cur_name;
    int counter = 1;
    for (auto friend_id : friends)
    {
        User* cur_friend = _us->getUserById(friend_id);
        cur_name = cur_friend->getName();
        std::cout << "friend number "<< counter <<" is: " << cur_name << std::endl;
        counter++;
    }
    std::cout << "thats all " << name << " friends" << std::endl;
    std::cout << std::endl << std::endl;
}


