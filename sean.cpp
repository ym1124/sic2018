#include "all.h"

void sean::doplaymode()//mainの*seから呼び出して
{
	playmode = PLAY;
}

void sean::dotitlemode()
{
	playmode = TITLE;
}

void sean::doclearmode()
{
	playmode = CLEAR;
}

void sean::doovermode()
{
	playmode = OVER;
}