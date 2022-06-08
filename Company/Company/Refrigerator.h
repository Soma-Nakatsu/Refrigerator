#pragma once
#include "ElectricAppliances.h"

// �①��
class Refrigerator : public ElectricAppliances
{
public:
	enum class MoveType
	{
		MOVE_TYPE_NONE = 0,		// ������
		MOVE_TYPE_IN,			// ����^�C�v�F��������
		MOVE_TYPE_OUT,			// ����^�C�v�F���g���o��
		MOVE_TYPE_CONFIRMATION	// ����^�C�v�F���g���m�F
	};

public:
	Refrigerator();
	~Refrigerator();

	void Update();

private:
	// ����^�C�v�̕ύX
	void ChangeMoveType();
	// �①�ɂ̒��g��\��
	void ShowContents();

private:
	MoveType		mMoveType;	// ����^�C�v
	vector<string>	mContents;	// �①�ɂ̒��g���X�g
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