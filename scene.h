#pragma once

enum{TITLE,PLAY,CLEAR,OVER};

class scene
{
public:
	int playmode;
	scene()
	{
		playmode = TITLE;
	}
};

void doplaymode(scene*);//mode�ύX
void dotitlemode(scene*);
void doclearmode(scene*);
void doovermode(scene*);