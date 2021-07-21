#include "Message.h"

Message::Message()
{
    text = "";
}

Message::Message(std::string str)
{
    text = str;
}

std::string Message::getText()
{
    return text;
}
