#pragma once

enum{TITLE,PLAY,CLEAR,OVER};

class sean
{
public:
	int playmode;
	sean()
	{
		playmode = TITLE;
	}
};

void doplaymode(sean*);//mode�ύX
void dotitlemode(sean*);
void doclearmode(sean*);
void doovermode(sean*);