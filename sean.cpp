#include "all.h"

void doplaymode(sean *se)//�I������Ƃ��Ɋe����main�̃|�C���^se��n����playmode�����������Ă��������B
{
	se->playmode = PLAY;
}

void dotitlemode(sean *se)
{
	se->playmode = TITLE;
}

void doclearmode(sean *se)
{
	se->playmode = CLEAR;
}

void doovermode(sean *se)
{
	se->playmode = OVER;
}