#pragma once
#include "ElectricAppliances.h"

// �①��
class Refrigerator : public ElectricAppliances
{
public:
	Refrigerator();
	~Refrigerator();

	void update();

private:
	void showContents();

private:
	vector<string> mContents;
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