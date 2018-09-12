#include"all.h"

void back::Drawback(scene se, player pl)

{
	if (se.playmode == TITLE)//�^�C�g����ʔw�i
	{
		DrawRectGraph(0, 0, 0, 0, WINDOW_X, WINDOW_Y, titleback_gh, true);
		if ((se.timer * 8) < 192)
		{
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 64 + se.timer * 8);
		}
		else
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

		if ((se.timer / 2) <= 8)
		{
			DrawRectGraph(204, 76 - (se.timer / 2), 0, 0, 166, 52, titleback_logo_gh, true);
		}
		else
			DrawRectGraph(204, 68, 0, 0, 166, 52, titleback_logo_gh, true);

		if (pl.pos_x >= 256)
		{
			DrawBox(368, 155, 368 + 7, 155 + 7, GetColor(200, 32, 32), true);
		}

		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	}

	if (se.playmode == PLAY || se.playmode == OVER)//�v���C��ʔw�i
	{
		if (se.playmode == OVER)y = temp_y;
		if (se.playmode == OVER)x = temp_x;
		switch (pl.directionMode)
		{
		case 0://�������
			if (y < -360)y = 0;
			DrawGraph(WINDOW_X / 2 - BACKSIDE_MARGIN, y, playback_gh, true);
			DrawGraph(WINDOW_X / 2 - BACKSIDE_MARGIN, WINDOW_Y + y, playback_gh, true);
			if (CheckHitKey(KEY_INPUT_4))doorFlg = true;
			Drawdoor(pl);
			y -= scrollspeed /*+ scrollspeedsetter*/;//�e�X�g�p�ύX
			break;

		case 2://�ォ�牺
			if (y > 360)y = 0;
			DrawGraph(BACKSIDE_MARGIN, y, playback_gh, true);
			DrawGraph(BACKSIDE_MARGIN, -WINDOW_Y + y, playback_gh, true);
			if (CheckHitKey(KEY_INPUT_4))doorFlg = true;
			Drawdoor(pl);
			y += scrollspeed /*+ scrollspeedsetter*/;
			break;

		//case 1://������E
		//	if (x > WINDOW_X)x = 0;
		//	DrawModiGraph(
		//		x, BACK_MARGIN,//����
		//		WINDOW_X + x, BACK_MARGIN,//�E��
		//		WINDOW_X + x, WINDOW_Y - BACK_MARGIN,//�E��
		//		x, WINDOW_Y - BACK_MARGIN,//����
		//		playbackside_gh[0], false);
		//	DrawModiGraph(
		//		-WINDOW_X + x, BACK_MARGIN,
		//		x, BACK_MARGIN,
		//		x, WINDOW_Y - BACK_MARGIN,
		//		-WINDOW_X + x, WINDOW_Y - BACK_MARGIN,
		//		playbackside_gh[0], false);
		//	x += SCROLL_SPEED + scrollspeedsetter;
		//	break;

		//case 3://�E���獶
		//	if (x < -WINDOW_X)x = 0;
		//	DrawModiGraph(
		//		x, BACK_MARGIN,//����
		//		WINDOW_X + x, BACK_MARGIN,//�E��
		//		WINDOW_X + x, WINDOW_Y - BACK_MARGIN,//�E��
		//		x, WINDOW_Y - BACK_MARGIN,//����
		//		playbackside_gh[0], false);
		//	DrawModiGraph(
		//		WINDOW_X + x, BACK_MARGIN,
		//		WINDOW_X * 2 + x, BACK_MARGIN,
		//		WINDOW_X * 2 + x, WINDOW_Y - BACK_MARGIN,
		//		WINDOW_X + x, WINDOW_Y - BACK_MARGIN,
		//		playbackside_gh[0], false);
		//	x -= SCROLL_SPEED + scrollspeedsetter;
		//	break;

		case 1://������E
			if (x >(BACKSIDE_WIDTH / 2) * 4)x = 0;
			DrawGraph(x + (BACKSIDE_WIDTH / 2) * 5, BACK_MARGIN, playbackside_gh[0], true);
			DrawGraph(x + (BACKSIDE_WIDTH / 2) * 4, BACK_MARGIN, playbackside_gh[0], true);
			DrawGraph(x + (BACKSIDE_WIDTH / 2)*3, BACK_MARGIN, playbackside_gh[0], true);
			DrawGraph(x + (BACKSIDE_WIDTH / 2)*2, BACK_MARGIN, playbackside_gh[0], true);
			DrawGraph(x + BACKSIDE_WIDTH / 2, BACK_MARGIN, playbackside_gh[0], true);
			DrawGraph(x, BACK_MARGIN, playbackside_gh[0], true);
			DrawGraph(x-BACKSIDE_WIDTH/2, BACK_MARGIN, playbackside_gh[0], true);
			DrawGraph(x - (BACKSIDE_WIDTH / 2)*2, BACK_MARGIN, playbackside_gh[0], true);
			DrawGraph(x - (BACKSIDE_WIDTH / 2)*3, BACK_MARGIN, playbackside_gh[0], true);
			DrawGraph(x - (BACKSIDE_WIDTH / 2) * 4, BACK_MARGIN, playbackside_gh[0], true);
			/*DrawGraph(-WINDOW_X + x, BACK_MARGIN, playbackside_gh[0], true);*/
			x += SCROLL_SPEED + scrollspeedsetter;
			break;

		case 3://�E���獶
			if (x < -(BACKSIDE_WIDTH / 2) * 4)x = 0;
			DrawGraph(x + (BACKSIDE_WIDTH / 2) * 7, BACK_MARGIN, playbackside_gh[0], true);
			DrawGraph(x + (BACKSIDE_WIDTH / 2) * 6, BACK_MARGIN, playbackside_gh[0], true);
			DrawGraph(x + (BACKSIDE_WIDTH / 2) * 5, BACK_MARGIN, playbackside_gh[0], true);
			DrawGraph(x + (BACKSIDE_WIDTH / 2) * 4, BACK_MARGIN, playbackside_gh[0], true);
			DrawGraph(x + (BACKSIDE_WIDTH / 2) * 3, BACK_MARGIN, playbackside_gh[0], true);
			DrawGraph(x + (BACKSIDE_WIDTH / 2) * 2, BACK_MARGIN, playbackside_gh[0], true);
			DrawGraph(x + BACKSIDE_WIDTH / 2, BACK_MARGIN, playbackside_gh[0], true);
			DrawGraph(x, BACK_MARGIN, playbackside_gh[0], true);
			x -= SCROLL_SPEED + scrollspeedsetter;
			break;
		}

		if (se.playmode == PLAY)temp_y = y;//���S���_�ŉ�ʎ~�߂�i�c�j
		if (se.playmode == PLAY)temp_x = x;
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
			DrawGraph(WINDOW_X / 2 - BACKSIDE_MARGIN, y, playbackedge_gh, true);
			DrawGraph(WINDOW_X / 2 - BACKSIDE_MARGIN, WINDOW_Y + y, playbackedge_gh, true);
			if (CheckHitKey(KEY_INPUT_4))doorFlg = true;//�e�X�g
			//Drawdoor(pl);
			y -= scrollspeed + scrollspeedsetter;//�e�X�g�p�ύX
			break;

		case 2:
			if (y > WINDOW_Y)y = 0;
			DrawGraph(BACKSIDE_MARGIN, y, playbackedge_gh, true);
			DrawGraph(BACKSIDE_MARGIN, -WINDOW_Y + y, playbackedge_gh, true);
			//Drawdoor(pl);
			y += scrollspeed + scrollspeedsetter;
			break;

		//case 1://������E
		//	if (fx > WINDOW_X)fx = 0;
		//	DrawModiGraph(
		//		fx, BACK_MARGIN,//����
		//		WINDOW_X + fx, BACK_MARGIN,//�E��
		//		WINDOW_X + fx, WINDOW_Y - BACK_MARGIN,//�E��
		//		fx, WINDOW_Y - BACK_MARGIN,//����
		//		playbackside_gh[1], true);
		//	DrawModiGraph(
		//		-WINDOW_X + fx, BACK_MARGIN,
		//		fx, BACK_MARGIN,
		//		fx, WINDOW_Y - BACK_MARGIN,
		//		-WINDOW_X + fx, WINDOW_Y - BACK_MARGIN,
		//		playbackside_gh[1], true);
		//	fx += (SCROLL_SPEED + scrollspeedsetter*0.8);
		//	break;

		//case 3://�E���獶
		//	if (fx < -WINDOW_X)fx = 0;
		//	DrawModiGraph(
		//		fx, BACK_MARGIN,//����
		//		WINDOW_X + fx, BACK_MARGIN,//�E��
		//		WINDOW_X + fx, WINDOW_Y - BACK_MARGIN,//�E��
		//		fx, WINDOW_Y - BACK_MARGIN,//����
		//		playbackside_gh[1], true);
		//	DrawModiGraph(
		//		WINDOW_X + fx, BACK_MARGIN,
		//		WINDOW_X * 2 + fx, BACK_MARGIN,
		//		WINDOW_X * 2 + fx, WINDOW_Y - BACK_MARGIN,
		//		WINDOW_X + fx, WINDOW_Y - BACK_MARGIN,
		//		playbackside_gh[1], true);
		//	fx -= (SCROLL_SPEED + scrollspeedsetter*0.8);
		//	break;

		case 1://������E
			if (fx > WINDOW_X)fx = 0;
			DrawGraph(fx, BACK_MARGIN, playbackside_gh[1], true);
			DrawGraph(-WINDOW_X + fx, BACK_MARGIN, playbackside_gh[1], true);
			fx += (SCROLL_SPEED + scrollspeedsetter*0.8);
			break;

		case 3://�E���獶
			if (fx < -WINDOW_X)fx = 0;
			DrawGraph(fx, BACK_MARGIN, playbackside_gh[1], true);
			DrawGraph(WINDOW_X + fx, BACK_MARGIN, playbackside_gh[1], true);
			fx -= (SCROLL_SPEED + scrollspeedsetter*0.8);
			break;

		}
		if (se.playmode == PLAY)temp_x = x;
	}
}



void back::Drawdoor(player pl)
{
	switch (doorFlg)
	{
	case false:
		anim_x = 0;
		//case0�̕�
		DrawRectGraph(WINDOW_X / 2 - BACKSIDE_MARGIN + EDGE_WIDTH, DOORPOS_Y + y-1, anim_x * 32, 96, 32, 96, door_gh, true);
		DrawRectGraph(WINDOW_X / 2 - BACKSIDE_MARGIN + EDGE_WIDTH, DOORPOS_Y + WINDOW_Y + y-1, anim_x * 32, 96, 32, 96, door_gh, true);
		DrawRectGraph(WINDOW_X / 2 - BACKSIDE_MARGIN + EDGE_WIDTH + 169, DOORPOS_Y + y, anim_x * 32, 0, 32, 96, door_gh, true);
		DrawRectGraph(WINDOW_X / 2 - BACKSIDE_MARGIN + EDGE_WIDTH + 169, DOORPOS_Y + WINDOW_Y + y, anim_x * 32, 0, 32, 96, door_gh, true);
		//case2�̕�
		DrawRectGraph(WINDOW_X / 2 - BACKSIDE_MARGIN + EDGE_WIDTH, DOORPOS_Y + y, anim_x * 32, 96, 32, 96, door_gh, true);
		DrawRectGraph(WINDOW_X / 2 - BACKSIDE_MARGIN + EDGE_WIDTH, DOORPOS_Y - WINDOW_Y + y, anim_x * 32, 96, 32, 96, door_gh, true);
		DrawRectGraph(WINDOW_X / 2 - BACKSIDE_MARGIN + EDGE_WIDTH + 169, DOORPOS_Y + y, anim_x * 32, 0, 32, 96, door_gh, true);
		DrawRectGraph(WINDOW_X / 2 - BACKSIDE_MARGIN + EDGE_WIDTH + 169, DOORPOS_Y - WINDOW_Y + y, anim_x * 32, 0, 32, 96, door_gh, true);
		break;

	case true:
		anim_x = (animCnt / 30) % 6;
		animCnt++;
		switch (pl.directionMode)
		{
		case 0:
			//���̔����J���`��
			DrawRectGraph(WINDOW_X / 2 - BACKSIDE_MARGIN + EDGE_WIDTH, DOORPOS_Y + y-1, anim_x * 32, 96, 32, 96, door_gh, true);
			DrawRectGraph(WINDOW_X / 2 - BACKSIDE_MARGIN + EDGE_WIDTH, DOORPOS_Y + WINDOW_Y + y-1, anim_x * 32, 96, 32, 96, door_gh, true);
			//�E�̔����J���`��
			DrawRectGraph(WINDOW_X / 2 - BACKSIDE_MARGIN + EDGE_WIDTH + 169, DOORPOS_Y + y, anim_x * 32, 0, 32, 96, door_gh, true);
			DrawRectGraph(WINDOW_X / 2 - BACKSIDE_MARGIN + EDGE_WIDTH + 169, DOORPOS_Y + WINDOW_Y + y, anim_x * 32, 0, 32, 96, door_gh, true);
			break;
		case 2:
			//���̔����J���`��
			DrawRectGraph(WINDOW_X / 2 - BACKSIDE_MARGIN + EDGE_WIDTH, DOORPOS_Y + y, anim_x * 32, 96, 32, 96, door_gh, true);
			DrawRectGraph(WINDOW_X / 2 - BACKSIDE_MARGIN + EDGE_WIDTH, DOORPOS_Y - WINDOW_Y + y, anim_x * 32, 96, 32, 96, door_gh, true);
			//�E�̔����J���`��
			DrawRectGraph(WINDOW_X / 2 - BACKSIDE_MARGIN + EDGE_WIDTH + 169, DOORPOS_Y + y, anim_x * 32, 0, 32, 96, door_gh, true);
			DrawRectGraph(WINDOW_X / 2 - BACKSIDE_MARGIN + EDGE_WIDTH + 169, DOORPOS_Y - WINDOW_Y + y, anim_x * 32, 0, 32, 96, door_gh, true);
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
	default:
		scrollspeedsetter = 2.0;
		break;
	}
}

void back::All(scene se, player pl)
{
	Move(pl);
	Drawback(se, pl);
}

void back::HitStop(scene se, player pl)
{
	scrollspeed = 0;
	scrollspeedsetter = 0;
	Drawback(se, pl);
}

void back::StopView()
{
	DrawGraph(WINDOW_X / 2 - BACKSIDE_MARGIN, y, playback_gh, true);
	DrawGraph(WINDOW_X / 2 - BACKSIDE_MARGIN, WINDOW_Y + y, playback_gh, true);
}