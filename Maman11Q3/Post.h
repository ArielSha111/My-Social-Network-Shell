#pragma once
#include <string>
#include "Media.h"
class Post
{
private:
	std::string text;
	Media* media;//maybe shuld be Media media*

public:
	 Post(std::string);
	 Post(std::string, Media*);
	 ~Post();
	std::string getText();
	Media* getMedia();
	void display();
	void displayText();
	void displayMedia();
	
	 
};

