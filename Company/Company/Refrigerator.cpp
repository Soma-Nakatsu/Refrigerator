#include "Refrigerator.h"

Refrigerator::Refrigerator()
	: mMoveType(MoveType::MOVE_TYPE_NONE)
	, mContents()
{
	mName = "�①��";

	FirstProcess();

	// ����^�C�v�ݒ�
	ChangeMoveType();
}

Refrigerator::~Refrigerator()
{
	mContents.clear();
}

void Refrigerator::Update()
{
	string message = "";
	switch (mMoveType)
	{
	
		break;
	case Refrigerator::MoveType::MOVE_TYPE_IN:
		message = "�������̂���͂��ĉ������B";
		break;
	case Refrigerator::MoveType::MOVE_TYPE_OUT:
		message = "�o�����̂���͂��ĉ������B";
		break;

	case Refrigerator::MoveType::MOVE_TYPE_NONE:
	case Refrigerator::MoveType::MOVE_TYPE_CONFIRMATION:
	default:
		break;
	}


	cout << "�������̂���͂��Ă��������BNakami�Ɠ��͂���ƒ��g���m�F�ł��܂��B" << endl;


	string in = "";
	cin >> in;

	// �I�����͂�����Ă����ꍇ�͉������Ȃ�
	if (End(in))
	{
		return;
	}

	// �{����

	if (in == "Nakami" || in == "nakami")
	{
		ShowContents();
	}
	else
	{
		cout << in + "�����܂����I" << endl;
		mContents.emplace_back(in);
	}
}

// ����^�C�v�̕ύX
void Refrigerator::ChangeMoveType()
{
	cout << "�������ꍇ�͂P" << endl;
	cout << "���o���ꍇ�͂Q" << endl;
	cout << "���g���m�F����ꍇ�͂R" << endl;
	cout << "����͂��ĉ������B" << endl;

	while (mMoveType == MoveType::MOVE_TYPE_NONE)
	{
		string in = "";
		cin >> in;

		if (in == "1")
		{
			mMoveType = MoveType::MOVE_TYPE_IN;
			break;
		}
		else if (in == "2")
		{
			mMoveType = MoveType::MOVE_TYPE_OUT;
			break;
		}
		else if (in == "3")
		{
			mMoveType = MoveType::MOVE_TYPE_CONFIRMATION;
			break;
		}
	}
}

// �①�ɂ̒��g��\��
void Refrigerator::ShowContents()
{
	cout << "�y�①�ɂ̒��g�z" << endl;

	auto size = (int)mContents.size();
	for (int i = 0; i < size; ++i)
	{
		cout << i + 1 << "." + mContents[i] << endl;
	}
}