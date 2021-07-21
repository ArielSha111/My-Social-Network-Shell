#include "USocial.h"
#include "User.h"
#include <exception>
#include <iostream>

#include "Photo.h"
#include "Audio.h"
#include "video.h"

int main()
{
	USocial us;
	User* u1 = us.registerUser("U1");
	User* u2 = us.registerUser("U2");
	User* u3 = us.registerUser("U3");
	User* u4 = us.registerUser("U4", true);
	User* u5 = us.registerUser("U5"); 


	USocial us2;
	User* u6 = us2.registerUser("U10");
	User* u7 = us2.registerUser("U10");
	User* u8 = us2.registerUser("U10");
	User* u9 = us2.registerUser("U10");
	User* u10 = us2.registerUser("U10");
	User* u11 = us2.registerUser("U10");
	User* u12 = us2.registerUser("U10");
	User* u13 = us2.registerUser("U10");
	

	try
	{
		us.removeUser(u13);
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}
	
	
	u1->post("Hello world!");
	u1->post("Hello world2!", new Photo());
	u1->post("Hello world3!", new Video());
	u1->post("Hello world4!", new Audio());
	u1->viewAllPosts();
	
	u2->post("I'm having a great time here :)", new Audio());
	u3->post("This is awesome!", new Photo());

	u5->addFriend(u1);
	u5->addFriend(u2);
	u5->viewFriendsPosts(); // should see only u1, u2 s' posts

	u4->sendMessage(u5, new Message("Buy Falafel!"));
	u5->viewReceivedMessages();

	//problem starts
	
	try
	{
		u3->sendMessage(u5, new Message("All your base are belong to us"));
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}
	
	u5->viewReceivedMessages();
	u3->addFriend(u5);

	u3->viewAllFriends();
	u5->viewAllFriends();

	u3->sendMessage(u5, new Message("All your base are belong to us"));
	
	u5->viewReceivedMessages();
	
	std::cout << u1->getName() << std:: endl;
	std::cout << u1->getId() << std::endl;
	std::cout << std::endl;

	std::cout << u2->getName() << std::endl;
	std::cout << u2->getId() << std::endl;
	std::cout << std::endl;

	std::cout << u3->getName() << std::endl;
	std::cout << u3->getId() << std::endl;
	std::cout << std::endl;

	std::cout << u4->getName() << std::endl;
	std::cout << u4->getId() << std::endl;
	std::cout << std::endl;

	std::cout << u5->getName() << std::endl;
	std::cout << u5->getId() << std::endl;
	std::cout << std::endl;
	
	return 0;
}