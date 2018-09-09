#include <stdlib.h>
#include <time.h>

#define PL_WIDTH 28

#define PL_HEIGHT 28

#define PL_SPEED_MAX 9

#define PL_SPEED_INC 0.2



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

#define EXPLOSIVE_POWER 15
#define EXPLOSION_MARGIN 17
#define PL_PARTS_START 63



bool check_hit_pos_y_rise(int, int, int, int);

bool check_hit_pos_y_fall(int, int, int, int);

bool checkHitBlock(int, int);

int direction_pl_pos_x(int);

int direction_pl_pos_y(int);





class player

{

public:

	int x, y, pos_x, pos_y, width, height;

	float speed;

	int fallVelocity;

	int acceleration;



	int hp;



	int item;



	int anim_x, anim_y;



	bool hitFlg;

	bool damageFlg;



	int directionMode;

	bool invincibleFlg;



	int player_gh;
	int exp_gh;
	////���S���֘A
	int player_gh_parts[18*6];//63����71�܂�
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



	bool plLiveFlg;



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



		hp = 3;



		hitFlg = false;

		damageFlg = false;

		directionMode = 0;

		invincibleFlg = false;

		srand(unsigned int(time(NULL)));
		for (int i = 0; i < 9; i++)
		{
			rngvalue[i] = rand() % 4*3;
		}



		player_gh = LoadGraph("Data/Image/player1.png");
		exp_gh = LoadGraph("Data/Image/effect1.png");



		anim_x = 0;

		anim_y = 0;



		flashCnt = 0;

		acceleCnt = 0;

		animCnt = 0;

		expCnt = 0;
		exp_x = 0;



	}



	void Move()

	{
		if (hp <= 0)
		{
		}
		else
		{
			switch (directionMode % 2)

			{

			case 0:



				if (CheckHitKey(KEY_INPUT_LEFT))

				{

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





			case 1:



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

	}



	void View()

	{

		if (hp > 0)

		{

			switch (damageFlg)

			{

			case false:

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



			case true:

				if (((flashCnt / 10) % 2) && flashCnt < FLASHCNT_MAX)

				{

					anim_x = (animCnt / 5) % 4;

					anim_y = PL_HEIGHT * 2;

					animCnt++;

					DrawRectGraph(pos_x, pos_y, anim_x*PL_WIDTH, anim_y, PL_WIDTH, PL_HEIGHT, player_gh, true, false);

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



			}

		}

		else

		{
			//���S�ށ[��
			LoadDivGraph("Data/Image/player1.png", 18 * 6, 18, 6, PL_WIDTH, PL_HEIGHT, player_gh_parts);
			DrawRectGraph(pos_x-EXPLOSION_MARGIN, pos_y-EXPLOSION_MARGIN, exp_x * 64, 0, 64, 64, exp_gh, true);
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
				DrawGraph(pos_x + parts_x[i], pos_y + parts_y[i], player_gh_parts[PL_PARTS_START + i], true);
			}
		}

	}



	void Accele()

	{

		if (acceleration < PL_MAX_ACCELERATION)

		{

			if (acceleCnt >= 120)

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



	void All()

	{

		Move();

		View();

		Accele();

	}







};







int direction_pl_pos_x(int);

int direction_pl_pos_y(int);
