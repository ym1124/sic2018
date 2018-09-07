#include "all.h"

void doplaymode(sean *se)//終了するときに各所でmainのポインタseを渡してplaymodeを書き換えてください。
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