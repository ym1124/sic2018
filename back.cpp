#include "ALL.h"

void back::Draw(sean se)
{
	if (se.playmode == TITLE)//�^�C�g����ʔw�i
	{
		DrawModiGraph(
			0 + BACKSIDE_MARGIN, 0,//����
			WINDOW_X - BACKSIDE_MARGIN, 0,//�E��
			WINDOW_X - BACKSIDE_MARGIN, WINDOW_Y,//�E��
			0 + BACKSIDE_MARGIN, WINDOW_Y,//����
			titleback_gh, false);
	}

	if (se.playmode == PLAY)//�v���C��ʔw�i
	{
		if (y < -WINDOW_Y)y = 0;//-WINDOW_Y�͂���
		DrawModiGraph(
			0 + BACKSIDE_MARGIN, y,//����
			WINDOW_X - BACKSIDE_MARGIN, y,//�E��
			WINDOW_X - BACKSIDE_MARGIN, WINDOW_Y + y,//�E��
			0 + BACKSIDE_MARGIN, WINDOW_Y + y,//����
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