#include"all.h"



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)

{

	ChangeWindowMode(true);

	SetGraphMode(WINDOW_X, WINDOW_Y, 32);

	if (DxLib_Init() == -1) return -1;

	SetDrawScreen(DX_SCREEN_BACK);


	player *pl = new player();

	block *bl = new block();

	back *bk = new back();

	sean *se = new sean();


	bool spaceFlg = false;

	int testback_1;

	int testback_2;

	double rad = 0;

	int rad_rand;

	player backscroll;



	testback_1 = LoadGraph("SIC_1_back_test1.png");

	testback_2 = LoadGraph("SIC1_back_test2.png");



	SetFontSize(128);

	int color = GetColor(0, 155, 250);






	srand((unsigned)time(NULL));





	while (ProcessMessage() != -1&&(se->playmode==TITLE||se->playmode==PLAY))

	{

		switch (pl->directionMode)

		{

		case BLOCK_RISE_MODE:

		case BLOCK_FALL_MODE:

			DrawRotaGraph(WINDOW_X / 2, WINDOW_Y / 2, 1.0, rad, testback_1, true, false);

			break;



		case PL_RIGHTSIDE_MODE:

		case PL_LEFTSIDE_MODE:

			DrawRotaGraph(WINDOW_X / 2, WINDOW_Y / 2, 1.0, rad, testback_2, true, false);

			break;



		default:

			break;

		}


		//backscroll.acceleration = pl->acceleration;

		//bk->All(backscroll);





		printfDx("%d", pl->acceleration);
		
		////////
		//�V�[���J��test
		if (se->playmode==TITLE&&pl->pos_x>=800)
		{
			doplaymode(se);
		}

		if (se->playmode == PLAY)
		{
			pl->All();
			bk->All(*se,*pl);
		}
		///////

		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)

		{

			delete pl;

			delete bl;



			exit(true);



		}





		if (CheckHitKey(KEY_INPUT_SPACE) && spaceFlg == false)

		{

			//�����ʒu����

			//pl->directionMode++;

			//rad_rand = rand() % 4;

			//rad = (DX_PI / 2)* rad_rand;

			//pl->pos_x = direction_pl_pos_x(rad_rand);

			//pl->pos_y = direction_pl_pos_y(rad_rand);





			//�u���b�N

			bl->blockFlg = true;





			spaceFlg = true;

		}



		//�c�̓����蔻��

		//�S�̓I�ɋC�����������邵�Ȃ�ł����ɏ����Ă�́H���Ԃ���ΏC��

		switch (pl->directionMode)

		{

		case BLOCK_RISE_MODE:

			if (check_hit_pos_y_rise(pl->pos_y, bl->pos_y, bl->blockNumber, bl->blockExistMode) && !pl->invincibleFlg && bl->nextBlockMargin <= 0)

			{

				if (checkHitBlock(pl->pos_x, bl->pos_x))

				{

					pl->hitFlg = true;

					bl->nextBlockMargin = pl->pos_y - (bl->pos_y + ((bl->blockNumber - bl->blockExistMode)*BLOCK_HEIGHT));

					if (bl->blockExistMode > 0)

					{

						bl->blockExistMode--;

						pl->acceleration--;

					}



					if (pl->acceleration <= 0)

					{

						pl->hp--;

						pl->damageFlg = true;

					}

				}

			}

			break;



		case BLOCK_FALL_MODE:

			if (check_hit_pos_y_fall(pl->pos_y, bl->pos_y, bl->blockNumber, bl->blockExistMode) && !pl->invincibleFlg && bl->nextBlockMargin <= 0 && !pl->damageFlg)

			{

				if (checkHitBlock(pl->pos_x, bl->pos_x))

				{

					pl->hitFlg = true;

					bl->nextBlockMargin = pl->pos_y - bl->pos_y - ((bl->blockNumber - bl->blockExistMode)*BLOCK_HEIGHT);

					if (bl->blockExistMode > 0)

					{

						bl->blockExistMode--;

						pl->acceleration--;

					}



					if (pl->acceleration <= 0)

					{

						pl->acceleration = 0;

						pl->hp--;

						pl->damageFlg = true;

					}

				}

			}

			break;





		default:

			break;

		}

		//�w�i�`��
		bk->All(*se,*pl);



		//�u���b�N�t���O�Ǘ�

		if (bl->blockFlg)

		{

			bl->Move();

			bl->ExistCheck();

			bl->View();

			switch (bl->directionMode)

			{

			case BLOCK_RISE_MODE:

				if (bl->pos_y < BLOCK_OUT_POS_Y)

				{

					bl->blockFlg = false;

					bl->GetPos();

				}

				break;



			case BLOCK_FALL_MODE:

				if (bl->pos_y > WINDOW_Y - BLOCK_OUT_POS_Y)

				{

					bl->blockFlg = false;

					bl->GetPos();

				}



			default:

				break;

			}

		}





		switch (bl->directionMode)

		{

		case BLOCK_RISE_MODE:

			if (pl->hitFlg && pl->pos_y < bl->pos_y + ((bl->blockNumber - bl->blockExistMode)*BLOCK_HEIGHT) && !pl->invincibleFlg)

			{

				pl->invincibleFlg = true;

			}

			else if (pl->invincibleFlg && !pl->damageFlg)

			{

				pl->invincibleFlg = false;

			}

			break;



		case BLOCK_FALL_MODE:

			if (pl->hitFlg && pl->pos_y > bl->pos_y - ((bl->blockNumber - bl->blockExistMode)*BLOCK_HEIGHT) + BLOCK_HEIGHT && !pl->invincibleFlg)

			{

				pl->invincibleFlg = true;

			}

			else if (pl->invincibleFlg && !pl->damageFlg)

			{

				pl->invincibleFlg = false;

			}

			break;



		default:

			break;

		}





		if (!CheckHitKey(KEY_INPUT_SPACE))

		{

			spaceFlg = false;

		}




		pl->All();





		//�������O��Ƃ��̊֌W�œ����ƍ��̂Ƃ��낿�傤�ǂ������ǁA������������ǂ��ɂ��Ȃ邩������Ȃ����A���邢�͂ǂ��ɂ��Ȃ�Ȃ���������Ȃ�



		switch (bl->directionMode)

		{

		case BLOCK_RISE_MODE:

			if (pl->hitFlg && pl->pos_y < bl->pos_y + ((bl->blockNumber - bl->blockExistMode)*BLOCK_HEIGHT) && !pl->invincibleFlg)

			{

				pl->invincibleFlg = true;

			}

			else if (pl->invincibleFlg && !pl->damageFlg)

			{

				pl->invincibleFlg = false;

			}

			break;



		case BLOCK_FALL_MODE:

			if (pl->hitFlg && pl->pos_y > bl->pos_y - ((bl->blockNumber - bl->blockExistMode)*BLOCK_HEIGHT) + BLOCK_HEIGHT && !pl->invincibleFlg)

			{

				pl->invincibleFlg = true;

			}

			else if (pl->invincibleFlg && !pl->damageFlg)

			{

				pl->invincibleFlg = false;

			}

			break;



		default:

			break;

		}







		//�ʒu�ύX

		if (CheckHitKey(KEY_INPUT_0))

		{

			pl->directionMode = BLOCK_RISE_MODE;

			bl->directionMode = BLOCK_RISE_MODE;

			pl->Direction();

			bl->GetPos();

		}



		if (CheckHitKey(KEY_INPUT_1))

		{

			pl->directionMode = PL_RIGHTSIDE_MODE;

			pl->Direction();

		}



		if (CheckHitKey(KEY_INPUT_2))

		{

			pl->directionMode = BLOCK_FALL_MODE;

			bl->directionMode = BLOCK_FALL_MODE;

			pl->Direction();

			bl->GetPos();

		}



		if (CheckHitKey(KEY_INPUT_3))

		{

			pl->directionMode = PL_LEFTSIDE_MODE;

			pl->Direction();

		}



		ScreenFlip();

		ClearDrawScreen();

	}





	delete pl;

	delete bl;

	delete bk;





	DxLib_End();



	return 0;

}