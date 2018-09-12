
#define PL_WIDTH 28

#define PL_HEIGHT 28

#define PL_SPEED_MAX 9

#define PL_SPEED_INC 0.2



#define BLOCK_RISE_MODE 0

#define BLOCK_FALL_MODE 2



#define PL_RIGHTSIDE_MODE 1

#define PL_LEFTSIDE_MODE 3



//�����ɑ΂��Ă̏����ʒu

#define PL_UP_FIRST_X WINDOW_X/2

#define PL_UP_FIRST_Y WINDOW_Y/3



#define PL_DOWN_FIRST_X WINDOW_X/2

#define PL_DOWN_FIRST_Y WINDOW_Y/3*2



#define PL_LEFT_FIRST_X WINDOW_X/4

#define PL_LEFT_FIRST_Y WINDOW_Y/2



#define PL_RIGHT_FIRST_X WINDOW_X/4*3

#define PL_RIGHT_FIRST_Y WINDOW_Y/2



#define PL_MAX_ACCELERATION 6



#define PL_HITSTOP_VAL 12



#define EXPLOSIVE_POWER 15

#define EXPLOSION_MARGIN 17

#define PL_PARTS_START 63



#define ACCELE_INC_TIME 60





bool check_hit_pos_y_rise(int, int, int, int);

bool check_hit_pos_y_fall(int, int, int, int);

bool check_hit_pos_x_goright(int, int);

bool check_hit_pos_x_goleft(int, int);

bool checkHitBlock(int, int);

bool checkHitObstacle(int, int);

int checkHitStop(int, int);

int direction_pl_pos_x(int);

int direction_pl_pos_y(int);

float sign(float n);

int getChangeDirectionModeLimit(int, int, int, int);





class player

{

public:

	int x, y, pos_x, pos_y, width, height;

	float speed;

	int fallVelocity;

	int acceleration;

	float targetSpeed;//�������
	int direction;//�������

	int accelerationTmp;



	int hp;



	int item;



	int anim_x, anim_y;



	bool hitFlg;

	bool damageFlg;

	bool changeDirectionModeFlg;

	bool changeDirectionStartFlg;



	int directionMode;

	int changeDirectionMode;

	int changeDirectionModeCnt;

	int changeDirectionModeLimit;

	bool invincibleFlg;



	int score;

	int combo;

	int combo_lim;



	int player_gh;

	int player_UP_gh;

	int player_gh_death;



	//���S���֘A



	int exp_gh;



	int player_gh_parts[18 * 6];

	int expCnt;

	int parts_x[9] = { 0 };

	double parts_y[9] = { 0 };

	bool expFlg[9] = { 0 };

	double y_temp[9] = { 0 };

	double y_prev[9] = { 0 };

	int exp_x;

	int rngvalue[9];



	int flashCnt;

	int acceleCnt;

	int animCnt;

	int hitstopCnt;



	bool plLiveFlg;

	bool hitstopFlg;



	int first, second, third, fourth;



	player()

	{

		x = WINDOW_X / 2;

		y = WINDOW_Y / 3;

		pos_x = WINDOW_X / 2;

		pos_y = WINDOW_Y / 3;

		width = PL_WIDTH;

		height = PL_HEIGHT;



		speed = 0;

		acceleration = 1;

		targetSpeed = 0;//�������
		direction = 0;//�������

		accelerationTmp = 1;



		hp = 3;



		hitFlg = false;

		damageFlg = false;

		changeDirectionStartFlg = false;

		changeDirectionModeFlg = false;



		first = 0;

		second = 0;

		third = 0;

		fourth = 0;



		score = 0;

		combo = 0;

		combo_lim = COMBO_LIMIT;



		directionMode = 0;

		changeDirectionMode = 0;

		changeDirectionModeCnt = 0;

		changeDirectionModeLimit = getChangeDirectionModeLimit(first, second, third, fourth);

		invincibleFlg = false;



		hitstopFlg = false;



		for (int i = 0; i < 9; i++)

		{

			rngvalue[i] = rand() % 4 * 3;

		}







		player_gh = LoadGraph("Data/Image/player1.png");

		player_UP_gh = LoadGraph("Data/Image/player1_UP.png");

		player_gh_death = LoadGraph("Data/Image/Pl_ps.png");

		exp_gh = LoadGraph("Data/Image/effect1.png");



		anim_x = 0;

		anim_y = 0;



		flashCnt = 0;

		acceleCnt = 0;

		animCnt = 0;

		hitstopCnt = 0;



		expCnt = 0;

		exp_x = 0;



	}



	void Move()

	{



		switch (directionMode)

		{

		case BLOCK_RISE_MODE:

		case BLOCK_FALL_MODE:

			targetSpeed = 0;//�������

			if (CheckHitKey(KEY_INPUT_LEFT))

			{
				/*if (speed < PL_SPEED_MAX)//������ƃR�����g�A�E�g
				{
				speed += PL_SPEED_INC;
				}*/

				if (speed < PL_SPEED_MAX)

				{

					speed += PL_SPEED_INC;

				}



				pos_x = pos_x - speed;

			}



			if (CheckHitKey(KEY_INPUT_RIGHT))

			{

				if (speed < PL_SPEED_MAX)

				{

					speed += PL_SPEED_INC;

				}



				pos_x = pos_x + speed;

			}



			if (!CheckHitKey(KEY_INPUT_RIGHT) && !CheckHitKey(KEY_INPUT_LEFT))

			{

				speed = 0;

			}





			break;





		case PL_RIGHTSIDE_MODE:

		case PL_LEFTSIDE_MODE:



			if (CheckHitKey(KEY_INPUT_UP))

			{

				if (speed < PL_SPEED_MAX)

				{

					speed += PL_SPEED_INC;

				}



				pos_y = pos_y - speed;

			}



			if (CheckHitKey(KEY_INPUT_DOWN))

			{

				if (speed < PL_SPEED_MAX)

				{

					speed += PL_SPEED_INC;

				}



				pos_y = pos_y + speed;

			}



			if (!CheckHitKey(KEY_INPUT_UP) && !CheckHitKey(KEY_INPUT_DOWN))

			{

				speed = 0;

			}





			break;





		default:

			break;

		}





	}



	void View()

	{

		if (hp > 0)

		{

			switch (damageFlg)

			{

			case false:

				switch (directionMode)

				{

				case BLOCK_RISE_MODE:

					if (acceleration == PL_MAX_ACCELERATION)

					{

						anim_x = (animCnt / 5) % 8;

						anim_y = PL_HEIGHT;

						animCnt++;

						DrawRectGraph(pos_x, pos_y, anim_x*PL_WIDTH, anim_y, PL_WIDTH, PL_HEIGHT, player_gh, true, false);

					}

					else

					{

						anim_x = (animCnt / 5) % 5;

						anim_y = 0;

						animCnt++;

						DrawRectGraph(pos_x, pos_y, anim_x*PL_WIDTH, anim_y, PL_WIDTH, PL_HEIGHT, player_gh, true, false);

					}

					break;



				case PL_RIGHTSIDE_MODE:

					anim_x = (animCnt / 5) % 8;

					anim_y = PL_HEIGHT;

					animCnt++;

					DrawRectRotaGraph(pos_x, pos_y, anim_x*PL_WIDTH, anim_y, PL_WIDTH, PL_HEIGHT, 1, DX_PI*0.5, player_gh, true, false);

					break;



				case BLOCK_FALL_MODE:

					if (acceleration == PL_MAX_ACCELERATION)

					{

						anim_x = (animCnt / 5) % 8;

						anim_y = PL_HEIGHT;

						animCnt++;

						DrawRectGraph(pos_x, pos_y, 503 - PL_WIDTH - (anim_x*PL_WIDTH), 167 - PL_HEIGHT * 2, PL_WIDTH, PL_HEIGHT, player_UP_gh, true, false);

					}

					else

					{

						anim_x = (animCnt / 5) % 5;

						anim_y = 0;

						animCnt++;

						DrawRectGraph(pos_x, pos_y, 503 - PL_WIDTH - (anim_x*PL_WIDTH), 167 - PL_HEIGHT, PL_WIDTH, PL_HEIGHT, player_UP_gh, true, false);

					}

					break;



				case PL_LEFTSIDE_MODE:

					anim_x = (animCnt / 5) % 8;

					anim_y = PL_HEIGHT;

					animCnt++;

					DrawRectRotaGraph(pos_x, pos_y, anim_x*PL_WIDTH, anim_y, PL_WIDTH, PL_HEIGHT, 1, DX_PI*1.5, player_gh, true, false);

					break;



				default:

					break;

				}

				break;



			case true:

				if (((flashCnt / 10) % 2) && flashCnt < FLASHCNT_MAX)

				{

					anim_x = (animCnt / 5) % 4;

					anim_y = PL_HEIGHT * 2;

					animCnt++;

					switch (directionMode)
					{
					case BLOCK_RISE_MODE:
						DrawRectGraph(pos_x, pos_y, anim_x*PL_WIDTH, anim_y, PL_WIDTH, PL_HEIGHT, player_gh, true, false);
						break;
					case PL_RIGHTSIDE_MODE:
						DrawRectRotaGraph(pos_x, pos_y, anim_x*PL_WIDTH, anim_y, PL_WIDTH, PL_HEIGHT, 1, DX_PI*0.5, player_gh, true, false);
						break;
					case BLOCK_FALL_MODE:
						DrawRectGraph(pos_x, pos_y, 503 - PL_WIDTH - (anim_x*PL_WIDTH), 167 - PL_HEIGHT * 2, PL_WIDTH, PL_HEIGHT, player_UP_gh, true, false);
						break;
					case PL_LEFTSIDE_MODE:
						DrawRectRotaGraph(pos_x, pos_y, anim_x*PL_WIDTH, anim_y, PL_WIDTH, PL_HEIGHT, 1, DX_PI*1.5, player_gh, true, false);
						break;
					default:
						break;
					}

					flashCnt++;

				}

				else if (flashCnt >= FLASHCNT_MAX)

				{

					damageFlg = false;

					invincibleFlg = false;

					flashCnt = 0;

				}

				else

				{

					flashCnt++;

				}

				break;

			}

		}

		else

		{

			//���S�ށ[��



			LoadDivGraph("Data/Image/player1.png", 18 * 6, 18, 6, PL_WIDTH, PL_HEIGHT, player_gh_parts);

			DrawRectGraph(pos_x - EXPLOSION_MARGIN, pos_y - EXPLOSION_MARGIN, exp_x * 64, 0, 64, 64, exp_gh, true);



			expCnt++;

			exp_x = expCnt / 3;



			for (int i = 0; i < 9; i++)

			{

				switch (i % 2)

				{

				case 1:

					parts_x[i] += expCnt / 20;

					break;



				case 0:

					parts_x[i] -= expCnt / 20;

					break;

				}



				if (expFlg[i] == false)



				{

					y_prev[i] = parts_y[i];

					parts_y[i] = parts_y[i] - (rngvalue[i]);//EXPLOSIVE_POWER

					expFlg[i] = true;

				}

				else

				{

					y_temp[i] = parts_y[i];

					parts_y[i] += (parts_y[i] - y_prev[i]) + 0.35;

					y_prev[i] = y_temp[i];

				}

				DrawRotaGraph(pos_x + parts_x[i], pos_y + parts_y[i], 1, expCnt / 3, player_gh_parts[PL_PARTS_START + i], true);

			}

		}

	}



	void StopView()

	{

		DrawRectGraph(pos_x, pos_y, 0, 0, PL_WIDTH, PL_HEIGHT, player_gh, true, false);

	}



	void Accele(scene se)

	{

		if (acceleration < PL_MAX_ACCELERATION && se.playmode == PLAY)

		{

			if (acceleCnt >= ACCELE_INC_TIME)

			{

				acceleration++;

				acceleCnt = 0;

			}

			else

			{

				acceleCnt++;

			}

		}

		//if (hitFlg && !invincibleFlg)

		//{

		//	acceleration--;

		//	invincibleFlg = true;

		//}

	}



	void Direction()

	{

		pos_x = direction_pl_pos_x(directionMode);

		pos_y = direction_pl_pos_y(directionMode);

	}



	void All(scene se)

	{

		Move();

		View();

		Accele(se);

	}







};







int direction_pl_pos_x(int);

int direction_pl_pos_y(int);


