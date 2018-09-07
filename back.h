#pragma once
#include "all.h"
#define SCROLL_SPEED 2

class back
{
public:
	int y;
	int scrollspeedsetter;
	int back_gh;
	back()
	{
		y = 0;
		scrollspeedsetter = 0;
		back_gh = LoadGraph("Data/Image/BG1.png");
	}
	void Draw();
	void Move(player);
	void All(player);
};