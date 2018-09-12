#include "all.h"

void doplaymode(scene *se)//�I������Ƃ��Ɋe����main�̃|�C���^se��n����playmode�����������Ă��������B
{
	se->playmode = PLAY;
}

void dotitlemode(scene *se)
{
	se->playmode = TITLE;
}

void doclearmode(scene *se)
{
	se->playmode = CLEAR;
}

void doovermode(scene *se)
{
	se->playmode = OVER;
}

void scene::Overmode(scene *se)
{
	Overselect(se);
	Drawover();
}

void scene::Drawover()
{
	DrawGraph(WINDOW_X*0.28, WINDOW_Y / 3, over_gh, true);
	switch (overselect)
	{
	case 0:
		DrawGraph(WINDOW_X*0.28, WINDOW_Y / 2 + 50, over_gh_title, true);
		DrawGraph(WINDOW_X*0.5, WINDOW_Y / 2 + 50, over_gh_retry, true);
		break;
	case 1://�^�C�g���I��
		DrawExtendGraph(WINDOW_X*0.28, WINDOW_Y / 2 + 50, WINDOW_X*0.28 + 75, WINDOW_Y / 2 + 80, over_gh_title, true);
		DrawGraph(WINDOW_X*0.5, WINDOW_Y / 2 + 50, over_gh_retry, true);
		break;
	case 2://���g���C�I��
		DrawGraph(WINDOW_X*0.28, WINDOW_Y / 2 + 50, over_gh_title, true);
		DrawExtendGraph(WINDOW_X*0.5, WINDOW_Y / 2 + 50, WINDOW_X*0.5 + 75, WINDOW_Y / 2 + 80, over_gh_retry, true);
	}
}

void scene::Overselect(scene *se)
{
	if (CheckHitKey(KEY_INPUT_LEFT))overselect = 1;
	if (CheckHitKey(KEY_INPUT_RIGHT))overselect = 2;

	if (overselect == 1 && CheckHitKey(KEY_INPUT_RETURN))
	{
		overselect = 0;
		dotitlemode(se);
	}
	if (overselect == 2 && CheckHitKey(KEY_INPUT_RETURN))
	{
		overselect = 0;
		retryFlg = true;
	}
}
