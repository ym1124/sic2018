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
	void doplaymode();//modeïœçX
	void dotitlemode();
	void doclearmode();
	void doovermode();
};