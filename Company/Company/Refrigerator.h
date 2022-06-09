#pragma once
#include "ElectricAppliances.h"

// �①��
class Refrigerator : public ElectricAppliances
{
public:
	enum MoveType
	{
		MOVE_TYPE_NONE = 0,		// ������
		MOVE_TYPE_IN,			// ����^�C�v�F��������
		MOVE_TYPE_OUT,			// ����^�C�v�F���g���o��
		MOVE_TYPE_CONFIRMATION,	// ����^�C�v�F���g���m�F

		MOVE_TYPE_NUM
	};

public:
	// �R���X�g���N�^/�f�X�g���N�^
	Refrigerator();
	~Refrigerator();

	// �X�V
	void Update() override;

private:
	// ������
	void init() override;

	// �e�L�X�g�t�@�C������mContents�̓��e��ݒ�
	bool SetupContents();
	// ����mContents�̓��e���e�L�X�g�ɏ�������
	void WriteContents();

	// ��������
	void AddContent();
	// ���g���o��
	void PutOutContent();
	// ���g���m�F����
	void ConfirmationContents();

	// �����đ�����s�����̃`�F�b�N
	void CheckContinue();
	// ����I��
	void ChangeMoveType();

private:
	MoveType		mMoveType;		// ����^�C�v
	vector<string>	mContents;		// �①�ɂ̒��g���X�g
};

// ���ꂽ���̂𒆐g���X�g�ɓo�^����
// �o�������̂𒆐g���X�g����폜����
// ���g���X�g�̒��g��\������

// �X�����
// �X�����o��
// �X�̎c�����\��

// NG���[�h���e�L�X�g�t�@�C������擾
// ����Ƃ��̗①�ɂ̒��g���X�g���O���e�L�X�g�ɕۑ�
// �J�����Ƃ��ɊO���ɕۑ��������g���X�g��ǂݍ���