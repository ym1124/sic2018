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