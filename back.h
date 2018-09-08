#pragma once
#include "all.h"
#define SCROLL_SPEED 2

class back
{
public:
	int x,y;
	double fx,fy;
	int scrollspeedsetter;
	int playback_gh, titleback_gh;
	int playbackside_gh[2];//[0]‚ª‰“Œi[1]‚ª‹ßŒi
	back()
	{
		x = 0;
		fx = 0;
		y = 0;
		fy = 0;
		scrollspeedsetter = 0;
		titleback_gh = LoadGraph("Data/Image/SIC_1_back_test1.png");
		LoadDivGraph("Data/Image/BG3.png",2,2,1,112,96,playbackside_gh);
		playback_gh = LoadGraph("Data/Image/BG1.png");
	}
	void Draw(scene,player);
	void Drawfront(scene, player);
	void Move(player);
	void All(scene,player);
};