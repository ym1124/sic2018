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
	void doplaymode();//mode�ύX
	void dotitlemode();
	void doclearmode();
	void doovermode();
};