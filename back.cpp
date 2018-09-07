#include "ALL.h"

void back::Draw()
{
	if (y == -WINDOW_Y+1)y =0;//-WINDOW_Y�͂���
	DrawModiGraph(
		0+BACKSIDE_MARGIN,y,//����
		WINDOW_X- BACKSIDE_MARGIN,y,//�E��
		WINDOW_X- BACKSIDE_MARGIN,WINDOW_Y+y,//�E��
		0+ BACKSIDE_MARGIN, WINDOW_Y+y,//����
		back_gh, false);
	DrawModiGraph(
		0+BACKSIDE_MARGIN, WINDOW_Y + y,
		WINDOW_X- BACKSIDE_MARGIN, WINDOW_Y + y,
		WINDOW_X- BACKSIDE_MARGIN, WINDOW_Y * 2+y,
		0+BACKSIDE_MARGIN, WINDOW_Y * 2+y,
		back_gh, false);
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
	y -= SCROLL_SPEED + scrollspeedsetter;
}

void back::All(player pl)
{
	Draw();
	Move(pl);
}