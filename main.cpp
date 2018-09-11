#include"all.h"



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)

{

	ChangeWindowMode(true);

	SetGraphMode(WINDOW_X, WINDOW_Y, 32);

	if (DxLib_Init() == -1) return -1;

	SetDrawScreen(DX_SCREEN_BACK);



	//�σX�N���[���T�C�Y

	SetGraphMode(WINDOW_X * MAX_WINDOW_EXTEND_RATE, WINDOW_Y * MAX_WINDOW_EXTEND_RATE, 32);//�`��ł���ő�̉𑜓x��ݒ�

	int windowSIze = MAX_WINDOW_EXTEND_RATE;//�E�B���h�E�g�嗦�̏����l

	int tempScreen = MakeScreen(WINDOW_X, WINDOW_Y, TRUE);//�`��\�ȉ���ʂ��쐬



	SetWindowSize(WINDOW_X * windowSIze, WINDOW_Y * windowSIze);





	player *pl = new player();

	player ppl;

	block *bl = new block();

	back *bk = new back();

	obstacle *ob = new obstacle();

	scene *se = new scene();

	ui *pui = new ui();



	bool spaceFlg = false;

	int testback_1;

	int testback_2;

	double rad = 0;

	int rad_rand;



	testback_1 = LoadGraph("Data/Image/SIC_1_back_test1.png");

	testback_2 = LoadGraph("Data/Image/SIC1_back_test2.png");



	SetFontSize(128);

	int color = GetColor(0, 155, 250);







	srand((unsigned)time(NULL));





	while (ProcessMessage() != -1)

	{
		//�L�[��ԍX�V //KB = �L�[�{�[�h //JOY = �W���C�p�b�h //[]�Ɏw��̃L�[�̒萔�����Ďg��

		gpUpdateKey();



		//����ʂɕ`��

		SetDrawScreen(tempScreen);



		//todo

		//



		//�T�C�Y�ύX

		if (KB[KEY_INPUT_F11] == 1)

		{

			windowSIze++;

			windowSIze = windowSIze % (MAX_WINDOW_EXTEND_RATE + 1);

			if (windowSIze == 0)windowSIze = 1;

			SetWindowSize(WINDOW_X * windowSIze, WINDOW_Y * windowSIze);

		}





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





		//�ʒu�ύX

		if (CheckHitKey(KEY_INPUT_0))

		{

			pl->directionMode = BLOCK_RISE_MODE;

			bl->directionMode = BLOCK_RISE_MODE;

			bk->y = 0;

			pl->Direction();

			bl->GetPos();

		}



		if (CheckHitKey(KEY_INPUT_1))

		{

			pl->directionMode = PL_RIGHTSIDE_MODE;

			bk->fx = 0;

			bk->x = 0;

			pl->Direction();

		}



		if (CheckHitKey(KEY_INPUT_2))

		{

			pl->directionMode = BLOCK_FALL_MODE;

			bl->directionMode = BLOCK_FALL_MODE;

			bk->y = 0;

			pl->Direction();

			bl->GetPos();

		}



		if (CheckHitKey(KEY_INPUT_3))

		{

			pl->directionMode = PL_LEFTSIDE_MODE;

			bk->fx = 0;

			bk->x = 0;

			pl->Direction();

		}



		if (CheckHitKey(KEY_INPUT_7))

		{

			pl->hp = 0;

		}


		///���[�h�]��
		if (se->playmode == TITLE&&pl->pos_x >= 400)

		{
			
			doplaymode(se);

		}

		if (se->playmode == TITLE)
		{
			bk->All(*se, *pl);
			pl->All(*se);
		}



		if (se->playmode == PLAY)

		{
			bk->All(*se, *pl);

			pui->All(*pl);

			pl->All(*se);

			bk->Drawbackfront(*se, *pl);

			if (pl->hp <= 0)
			{
				doovermode(se);
			}

		}

		if (se->playmode==OVER)
		{
			bk->All(*se, *pl);

			pui->All(*pl);

			pl->All(*se);

			bk->Drawbackfront(*se, *pl);

			se->Overmode(se);

		}




		//�w�i

		//�܂����[�v���ĂȂ��̂Ń��[�v������

		/*bk->All(*se, *pl);*/



		HitStop(*bl, *pl);



		pl->hitstopCnt--;

		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)

		{

			delete pl;

			delete bl;

			delete bk;

			delete se;

			delete ob;



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



			switch (pl->directionMode)

			{

			case BLOCK_RISE_MODE:

			case BLOCK_FALL_MODE:

				//�u���b�N

				bl->blockFlg = true;



			case PL_RIGHTSIDE_MODE:

			case PL_LEFTSIDE_MODE:

				//�����[�h�̏�Q��

				ob->obstacleFlg = true;

			}





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



						pl->hitstopCnt = checkHitStop(bl->blockNumber, bl->blockExistMode);



					}



					if (pl->acceleration <= 0 && pl->hitstopFlg)

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



						pl->hitstopCnt = checkHitStop(bl->blockNumber, bl->blockExistMode);



					}



					if (pl->acceleration <= 0 && pl->hitstopFlg)

					{

						pl->acceleration = 0;

						pl->hp--;

						pl->damageFlg = true;

					}

				}

			}

			break;



		case PL_RIGHTSIDE_MODE:

			if (check_hit_pos_x_goright(pl->pos_x, ob->pos_x) && !pl->damageFlg)

			{

				if (checkHitObsacle(pl->pos_y, ob->pos_y))

				{

					pl->damageFlg = true;

					pl->hp--;

				}

			}





		default:

			break;

		}





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

				break;



			default:

				break;

			}

		}





		//��Q���t���O�Ǘ�

		if (ob->obstacleFlg)

		{

			ob->Move();

			ob->View();

			switch (ob->directionMode)

			{

			case PL_RIGHTSIDE_MODE:

				if (ob->pos_x > WINDOW_X + OBSTACLE_OUT_POS_X)

				{

					ob->obstacleFlg = false;

					ob->GetPos();

				}

				break;



			case PL_LEFTSIDE_MODE:

				if (ob->pos_x < -OBSTACLE_OUT_POS_X)

				{

					ob->obstacleFlg = false;

					ob->GetPos();

				}

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









		//����ʂ�`��

		SetDrawScreen(DX_SCREEN_BACK);

		DrawExtendGraph(0, 0, WINDOW_X * MAX_WINDOW_EXTEND_RATE, WINDOW_Y * MAX_WINDOW_EXTEND_RATE, tempScreen, FALSE);



		ScreenFlip();

		ClearDrawScreen();

	}





	delete pl;

	delete bl;

	delete bk;

	delete ob;

	delete se;





	DxLib_End();



	return 0;

}