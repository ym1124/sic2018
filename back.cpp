#include "ALL.h"

void back::Draw(sean se,player pl)
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
		switch (pl.directionMode)
		{
		case 0:
			if (y < -WINDOW_Y)y = 0;
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
			break;
		case 2:
			if (y > WINDOW_Y)y = 0;
			DrawModiGraph(
				0 + BACKSIDE_MARGIN, y,//����
				WINDOW_X - BACKSIDE_MARGIN, y,//�E��
				WINDOW_X - BACKSIDE_MARGIN, WINDOW_Y + y,//�E��
				0 + BACKSIDE_MARGIN, WINDOW_Y + y,//����
				playback_gh, false);
			DrawModiGraph(
				0 + BACKSIDE_MARGIN, -WINDOW_Y + y,
				WINDOW_X - BACKSIDE_MARGIN, -WINDOW_Y + y,
				WINDOW_X - BACKSIDE_MARGIN, y,
				0 + BACKSIDE_MARGIN, y,
				playback_gh, false);
			y += SCROLL_SPEED + scrollspeedsetter;
			break;
		case 1:
			if (x > WINDOW_X)x = 0;
			DrawModiGraph(
				x, BACK_MARGIN,//����
				WINDOW_X +x, BACK_MARGIN,//�E��
				WINDOW_X +x, WINDOW_Y-BACK_MARGIN,//�E��
				x, WINDOW_Y-BACK_MARGIN,//����
				playback_gh, false);
			DrawModiGraph(
				-WINDOW_X + x, BACK_MARGIN,
				x, BACK_MARGIN,
				x, WINDOW_Y - BACK_MARGIN,
				-WINDOW_X+x, WINDOW_Y - BACK_MARGIN,
				playback_gh, false);
			x += SCROLL_SPEED + scrollspeedsetter;
			break;
		case 3:
			if (x < -WINDOW_X)x = 0;
			DrawModiGraph(
				x, BACK_MARGIN,//����
				WINDOW_X + x, BACK_MARGIN,//�E��
				WINDOW_X + x, WINDOW_Y - BACK_MARGIN,//�E��
				x, WINDOW_Y - BACK_MARGIN,//����
				playback_gh, false);
			DrawModiGraph(
				WINDOW_X + x, BACK_MARGIN,
				WINDOW_X*2+x, BACK_MARGIN,
				WINDOW_X*2+x, WINDOW_Y - BACK_MARGIN,
				WINDOW_X + x, WINDOW_Y - BACK_MARGIN,
				playback_gh, false);
			x -= SCROLL_SPEED + scrollspeedsetter;
			break;
		}
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
	Draw(se,pl);
	Move(pl);
}