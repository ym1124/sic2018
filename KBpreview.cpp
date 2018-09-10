#include"ALL.h"



int KB[256] = { 0 };

int JOY[26] = { 0 };

XINPUT_STATE inputJoy;



int gpUpdateKey() {

	char tmpKey[256]; // ���݂̃L�[�̓��͏�Ԃ��i�[����

	GetHitKeyStateAll(tmpKey); // �S�ẴL�[�̓��͏�Ԃ𓾂�

	GetJoypadXInputState(DX_INPUT_PAD1, &inputJoy);



	for (int i = 0; i < 256; i++) {

		if (tmpKey[i] != 0) { // i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����

			KB[i]++;     // ���Z

		}

		else {              // ������Ă��Ȃ����

			KB[i] = 0;   // 0�ɂ���

		}

	}

	for (int j = 0; j < 16; j++) {

		if (inputJoy.Buttons[j] != 0) { // i�Ԃ̃L�[�R�[�h�ɑΉ�����{�^����������Ă�����

			JOY[j]++;     // ���Z

		}

		else {              // ������Ă��Ȃ����

			JOY[j] = 0;   // 0�ɂ���

		}

	}



	/*L�X�e�B�b�N����*/

	if (inputJoy.ThumbLX > 0)				// L�X�e�B�b�N���E�ɓ|����Ă�����

		JOY[XINPUT_THUMB_L_RIGHT]++;	// ���Z

	else								// ������Ă��Ȃ����

		JOY[XINPUT_THUMB_L_RIGHT] = 0;  // 0�ɂ���



	if (inputJoy.ThumbLX < 0)				// L�X�e�B�b�N�����ɓ|����Ă�����

		JOY[XINPUT_THUMB_L_LEFT]++;		// ���Z

	else								// ������Ă��Ȃ����

		JOY[XINPUT_THUMB_L_LEFT] = 0;   // 0�ɂ���



	if (inputJoy.ThumbLY > 0)				// L�X�e�B�b�N����ɓ|����Ă�����

		JOY[XINPUT_THUMB_L_UP]++;		// ���Z

	else								// ������Ă��Ȃ����

		JOY[XINPUT_THUMB_L_UP] = 0;		// 0�ɂ���



	if (inputJoy.ThumbLY < 0)				// L�X�e�B�b�N�����ɓ|����Ă�����

		JOY[XINPUT_THUMB_L_DOWN]++;		// ���Z

	else								// ������Ă��Ȃ����

		JOY[XINPUT_THUMB_L_DOWN] = 0;   // 0�ɂ���



										/*R�X�e�B�b�N����*/

	if (inputJoy.ThumbLX > 0)				// R�X�e�B�b�N���E�ɓ|����Ă�����

		JOY[XINPUT_THUMB_R_RIGHT]++;	// ���Z

	else								// ������Ă��Ȃ����

		JOY[XINPUT_THUMB_R_RIGHT] = 0;  // 0�ɂ���



	if (inputJoy.ThumbLX < 0)				// R�X�e�B�b�N�����ɓ|����Ă�����

		JOY[XINPUT_THUMB_R_LEFT]++;		// ���Z

	else								// ������Ă��Ȃ����

		JOY[XINPUT_THUMB_R_LEFT] = 0;   // 0�ɂ���



	if (inputJoy.ThumbLY > 0)				// R�X�e�B�b�N����ɓ|����Ă�����

		JOY[XINPUT_THUMB_R_UP]++;		// ���Z

	else								// ������Ă��Ȃ����

		JOY[XINPUT_THUMB_R_UP] = 0;		// 0�ɂ���



	if (inputJoy.ThumbLY < 0)				// R�X�e�B�b�N�����ɓ|����Ă�����

		JOY[XINPUT_THUMB_R_DOWN]++;		// ���Z

	else								// ������Ă��Ȃ����

		JOY[XINPUT_THUMB_R_DOWN] = 0;   // 0�ɂ���



										/*�g���K�[����*/

	if (inputJoy.LeftTrigger != 0)			// L�g���K�[��������Ă�����

		JOY[XINPUT_LEFT_TRIGGER]++;		// ���Z

	else								// ������Ă��Ȃ����

		JOY[XINPUT_LEFT_TRIGGER] = 0;	// 0�ɂ���



	if (inputJoy.RightTrigger != 0)		// R�g���K�[��������Ă�����

		JOY[XINPUT_RIGHT_TRIGGER]++;	// ���Z

	else								// ������Ă��Ȃ����

		JOY[XINPUT_RIGHT_TRIGGER] = 0;	// 0�ɂ���





	return 0;

}

