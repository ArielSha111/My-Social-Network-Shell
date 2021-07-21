#include "Post.h"
#include <iostream>


 Post::Post(std::string str)
{
    text = str;
}

Post::~Post()
{
    delete media;
}
 Post::Post(std::string str, Media* m)
{
    text = str;
    media = m;
}

std::string Post::getText()
{
    return text;
}

Media* Post::getMedia()
{
    return media;
}

void Post::display()
{
    displayText();
    if (media)
        displayMedia();

}

void Post::displayText()
{
    std::cout <<"\t\ttext of post : " << text << std::endl;//print the text
}

void Post::displayMedia()
{
    std::cout << "\t\tmedia of post : ";
    media->display();//and display the media
}
