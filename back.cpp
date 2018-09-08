#include "ALL.h"

void back::Draw(sean se)
{
	if (se.playmode == TITLE)//タイトル画面背景
	{
		DrawModiGraph(
			0 + BACKSIDE_MARGIN, 0,//左上
			WINDOW_X - BACKSIDE_MARGIN, 0,//右上
			WINDOW_X - BACKSIDE_MARGIN, WINDOW_Y,//右下
			0 + BACKSIDE_MARGIN, WINDOW_Y,//左下
			titleback_gh, false);
	}

	if (se.playmode == PLAY)//プレイ画面背景
	{
		if (y < -WINDOW_Y)y = 0;//-WINDOW_Yはだめ
		DrawModiGraph(
			0 + BACKSIDE_MARGIN, y,//左上
			WINDOW_X - BACKSIDE_MARGIN, y,//右上
			WINDOW_X - BACKSIDE_MARGIN, WINDOW_Y + y,//右下
			0 + BACKSIDE_MARGIN, WINDOW_Y + y,//左下
			playback_gh, false);
		DrawModiGraph(
			0 + BACKSIDE_MARGIN, WINDOW_Y + y,
			WINDOW_X - BACKSIDE_MARGIN, WINDOW_Y + y,
			WINDOW_X - BACKSIDE_MARGIN, WINDOW_Y * 2 + y,
			0 + BACKSIDE_MARGIN, WINDOW_Y * 2 + y,
			playback_gh, false);
		y -= SCROLL_SPEED + scrollspeedsetter;
	}
}

void back::Move(player pl)
{
	switch (pl.acceleration)
	{
	case 0:
		scrollspeedsetter = 0;
		break;
	case 1:
		scrollspeedsetter = 1;
		break;
	case 2:
		scrollspeedsetter = 2;
		break;
	case 3:
		scrollspeedsetter = 3;
		break;
	}
}

void back::All(sean se,player pl)
{
	Draw(se);
	Move(pl);
}