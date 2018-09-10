#include "ALL.h"



void back::Drawback(scene se, player pl)

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

		case 0://�������

			if (y < -360)y = 0;

			DrawGraph(BACKSIDE_MARGIN, y,playback_gh, true);

			DrawGraph(BACKSIDE_MARGIN, WINDOW_Y + y,playback_gh, true);

			if (CheckHitKey(KEY_INPUT_4))doorFlg = true;

			Drawdoor(pl);

			y -= SCROLL_SPEED /*+ scrollspeedsetter*/;//�e�X�g�p�ύX

			break;

		case 2://�ォ�牺

			if (y > 360)y = 0;

			DrawGraph(BACKSIDE_MARGIN, y,playback_gh, true);

			DrawGraph(BACKSIDE_MARGIN, -WINDOW_Y + y,playback_gh, true);

			if (CheckHitKey(KEY_INPUT_4))doorFlg = true;

			Drawdoor(pl);

			y += SCROLL_SPEED /*+ scrollspeedsetter*/;

			break;

		case 1://������E

			if (x > WINDOW_X)x = 0;

			DrawModiGraph(

				x, BACK_MARGIN,//����

				WINDOW_X + x, BACK_MARGIN,//�E��

				WINDOW_X + x, WINDOW_Y - BACK_MARGIN,//�E��

				x, WINDOW_Y - BACK_MARGIN,//����

				playbackside_gh[0], false);

			DrawModiGraph(

				-WINDOW_X + x, BACK_MARGIN,

				x, BACK_MARGIN,

				x, WINDOW_Y - BACK_MARGIN,

				-WINDOW_X + x, WINDOW_Y - BACK_MARGIN,

				playbackside_gh[0], false);

			x += SCROLL_SPEED + scrollspeedsetter;

			break;

		case 3://�E���獶

			if (x < -WINDOW_X)x = 0;

			DrawModiGraph(

				x, BACK_MARGIN,//����

				WINDOW_X + x, BACK_MARGIN,//�E��

				WINDOW_X + x, WINDOW_Y - BACK_MARGIN,//�E��

				x, WINDOW_Y - BACK_MARGIN,//����

				playbackside_gh[0], false);

			DrawModiGraph(

				WINDOW_X + x, BACK_MARGIN,

				WINDOW_X * 2 + x, BACK_MARGIN,

				WINDOW_X * 2 + x, WINDOW_Y - BACK_MARGIN,

				WINDOW_X + x, WINDOW_Y - BACK_MARGIN,

				playbackside_gh[0], false);

			x -= SCROLL_SPEED + scrollspeedsetter;

			break;

		}

	}

}



void back::Drawbackfront(scene se, player pl)

{

	if (se.playmode == PLAY)//�v���C��ʔw�i

	{

		switch (pl.directionMode)

		{
		case 0:
			if (y < -WINDOW_Y)y = 0;

			DrawGraph(BACKSIDE_MARGIN, y,playbackedge_gh, true);

			DrawGraph(BACKSIDE_MARGIN, WINDOW_Y + y,playbackedge_gh, true);

			if (CheckHitKey(KEY_INPUT_4))doorFlg = true;//�e�X�g

			Drawdoor(pl);

			y -= SCROLL_SPEED + scrollspeedsetter;//�e�X�g�p�ύX

			break;

		case 2:
			if (y > WINDOW_Y)y = 0;

			DrawGraph(BACKSIDE_MARGIN, y,playbackedge_gh, true);

			DrawGraph(BACKSIDE_MARGIN, -WINDOW_Y + y,playbackedge_gh, true);

			Drawdoor(pl);

			y += SCROLL_SPEED + scrollspeedsetter;

			break;

		case 1://������E

			if (fx > WINDOW_X)fx = 0;

			DrawModiGraph(

				fx, BACK_MARGIN,//����

				WINDOW_X + fx, BACK_MARGIN,//�E��

				WINDOW_X + fx, WINDOW_Y - BACK_MARGIN,//�E��

				fx, WINDOW_Y - BACK_MARGIN,//����

				playbackside_gh[1], true);

			DrawModiGraph(

				-WINDOW_X + fx, BACK_MARGIN,

				fx, BACK_MARGIN,

				fx, WINDOW_Y - BACK_MARGIN,

				-WINDOW_X + fx, WINDOW_Y - BACK_MARGIN,

				playbackside_gh[1], true);

			fx += (SCROLL_SPEED + scrollspeedsetter*0.8);

			break;

		case 3://�E���獶

			if (fx < -WINDOW_X)fx = 0;

			DrawModiGraph(

				fx, BACK_MARGIN,//����

				WINDOW_X + fx, BACK_MARGIN,//�E��

				WINDOW_X + fx, WINDOW_Y - BACK_MARGIN,//�E��

				fx, WINDOW_Y - BACK_MARGIN,//����

				playbackside_gh[1], true);

			DrawModiGraph(

				WINDOW_X + fx, BACK_MARGIN,

				WINDOW_X * 2 + fx, BACK_MARGIN,

				WINDOW_X * 2 + fx, WINDOW_Y - BACK_MARGIN,

				WINDOW_X + fx, WINDOW_Y - BACK_MARGIN,

				playbackside_gh[1], true);

			fx -= (SCROLL_SPEED + scrollspeedsetter*0.8);

			break;

		}

	}

}



void back::Drawdoor(player pl)

{

	switch (doorFlg)

	{

	case false:

		anim_x = 0;
		//case0�̕�
		DrawRectGraph(BACKSIDE_MARGIN + EDGE_WIDTH, DOORPOS_Y + y, anim_x * 32, 96, 32, 96, door_gh, true);
		DrawRectGraph(BACKSIDE_MARGIN + EDGE_WIDTH, DOORPOS_Y + WINDOW_Y + y, anim_x * 32, 96, 32, 96, door_gh, true);
		DrawRectGraph(BACKSIDE_MARGIN + EDGE_WIDTH + 169, DOORPOS_Y + y, anim_x * 32, 0, 32, 96, door_gh, true);
		DrawRectGraph(BACKSIDE_MARGIN + EDGE_WIDTH + 169, DOORPOS_Y + WINDOW_Y + y, anim_x * 32, 0, 32, 96, door_gh, true);
		//case2�̕�
		DrawRectGraph(BACKSIDE_MARGIN + EDGE_WIDTH, DOORPOS_Y + y, anim_x * 32, 96, 32, 96, door_gh, true);
		DrawRectGraph(BACKSIDE_MARGIN + EDGE_WIDTH, DOORPOS_Y - WINDOW_Y + y, anim_x * 32, 96, 32, 96, door_gh, true);
		DrawRectGraph(BACKSIDE_MARGIN + EDGE_WIDTH + 169, DOORPOS_Y + y, anim_x * 32, 0, 32, 96, door_gh, true);
		DrawRectGraph(BACKSIDE_MARGIN + EDGE_WIDTH + 169, DOORPOS_Y - WINDOW_Y + y, anim_x * 32, 0, 32, 96, door_gh, true);
		break;

	case true:

		anim_x = (animCnt / 30) % 5;
		
		animCnt++;
		switch (pl.directionMode)
		{
		case 0:
			//���̔����J���`��
			DrawRectGraph(BACKSIDE_MARGIN + EDGE_WIDTH, DOORPOS_Y + y, anim_x * 32, 96, 32, 96, door_gh, true);

			DrawRectGraph(BACKSIDE_MARGIN + EDGE_WIDTH, DOORPOS_Y + WINDOW_Y + y, anim_x * 32, 96, 32, 96, door_gh, true);
			//�E�̔����J���`��
			DrawRectGraph(BACKSIDE_MARGIN + EDGE_WIDTH + 169, DOORPOS_Y + y, anim_x * 32, 0, 32, 96, door_gh, true);

			DrawRectGraph(BACKSIDE_MARGIN + EDGE_WIDTH + 169, DOORPOS_Y + WINDOW_Y + y, anim_x * 32, 0, 32, 96, door_gh, true);
			break;
		case 2:
			//���̔����J���`��
			DrawRectGraph(BACKSIDE_MARGIN + EDGE_WIDTH, DOORPOS_Y + y, anim_x * 32, 96, 32, 96, door_gh, true);

			DrawRectGraph(BACKSIDE_MARGIN + EDGE_WIDTH, DOORPOS_Y - WINDOW_Y + y, anim_x * 32, 96, 32, 96, door_gh, true);
			//�E�̔����J���`��
			DrawRectGraph(BACKSIDE_MARGIN + EDGE_WIDTH + 169, DOORPOS_Y + y, anim_x * 32, 0, 32, 96, door_gh, true);

			DrawRectGraph(BACKSIDE_MARGIN + EDGE_WIDTH + 169, DOORPOS_Y - WINDOW_Y + y, anim_x * 32, 0, 32, 96, door_gh, true);
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

		scrollspeedsetter = 0.5;

		break;

	case 2:

		scrollspeedsetter = 1;

		break;

	case 3:

		scrollspeedsetter = 1.5;

		break;

	}

}



void back::All(scene se, player pl)

{

	Drawback(se, pl);

	Move(pl);

}