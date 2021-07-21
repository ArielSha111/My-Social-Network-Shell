#pragma once
#include "USocial.h"
#include <string>
#include <list>
#include <map>
#include "Post.h"
#include "Message.h"

class User
{
	friend class USocial;
	
protected:
	USocial* _us;
	unsigned long id;
	std::string name;
	std::list<unsigned long> friends;
	std::list<Post*> posts;
	std::list <Message*> receivedMsgs;

public:
	
	User();
	~User();
	User(int, std::string, USocial*);
	long getId();
	std::string getName();
	void addFriend(User*);
	void addFriendFromOutside(User* user);
	void removeFriend(User*);
	void removeFriendFromOutside(User* user);
	void post(std::string);
	void post(std::string, Media*);
	std::list<Post*> getPosts();
	void viewFriendsPosts();
	void receiveMessage(Message*);
	virtual void sendMessage(User*, Message*);
	void viewReceivedMessages();
	void viewAllPosts();
	void viewAllFriends();
	bool isMyFriend(User*);
};


