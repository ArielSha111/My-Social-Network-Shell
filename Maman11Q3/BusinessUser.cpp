#include "BusinessUser.h"

BusinessUser:: BusinessUser(int needed_id, std::string needed_name, USocial* us)
{
	id = needed_id;
	name = needed_name;
	_us = us;
}

BusinessUser::~BusinessUser()
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


void BusinessUser::sendMessage(User* u, Message* m)
{
	if (u)
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
		throw std::invalid_argument("the given user  is null");
	}
}

