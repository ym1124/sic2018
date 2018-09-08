#pragma once
#include "all.h"
#define SCROLL_SPEED 2

class back
{
public:
	int y;
	int scrollspeedsetter;
	int playback_gh,titleback_gh;
	back()
	{
		y = 0;
		scrollspeedsetter = 0;
		titleback_gh = LoadGraph("Data/Image/SIC_1_back_test1.png");
		playback_gh = LoadGraph("Data/Image/BG1.png");
	}
	void Draw(sean);
	void Move(player);
	void All(sean,player);
};