#pragma once
#include "Utility.h"

// �d�����i���N���X
class ElectricAppliances
{
public:
	// �R���X�g���N�^/�f�X�g���N�^
	ElectricAppliances();
	~ElectricAppliances();

	// �X�V
	virtual void Update();

	bool ISEnd() { return mIsEnd; }

protected:
	// ������
	virtual void init();

	// �J�n���菈��
	void Start();
	// �I�����菈��
	bool End(string in);

	// �J�n���ɕ\�����镶���\��
	void ViewStartString();

protected:
	bool	mIsEnd;	// �I�����邩�H
	string	mName;	// �ݒ肵�����O
};