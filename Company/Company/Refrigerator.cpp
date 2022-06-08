#include "Refrigerator.h"

Refrigerator::Refrigerator()
	: mMoveType(MoveType::MOVE_TYPE_NONE)
	, mContents()
{
	mName = "�①��";

	FirstProcess();

	// ����I��
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
	case Refrigerator::MoveType::MOVE_TYPE_IN:
		// ��������
		AddContent();
		break;
	case Refrigerator::MoveType::MOVE_TYPE_OUT:
		// ���g���o��
		PutOutContent();
		break;
	case Refrigerator::MoveType::MOVE_TYPE_CONFIRMATION:
		// ���g���m�F����
		ConfirmationContent();
		break;

	case Refrigerator::MoveType::MOVE_TYPE_NONE:
	
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

// ��������
void Refrigerator::AddContent()
{
	cout << "�������̂���͂��Ă��������B" << endl;

	string content = "";
	cin >> content;

	mContents.emplace_back(content);
	cout << content + "�����܂����I" << endl;

	cout << "�����Ă��̂����܂����H" << endl;
	cout << "�͂��F1" << endl;
	cout << "�������F�Q" << endl;

	bool isSelect = false;
	while (!isSelect)
	{
		string select = "";
		cin >> select;

		if (select != "1" && select != "2")
		{
			continue;
		}

		// �����Ă��̂����Ȃ��ꍇ�͓���I����
		if (select == "2")
		{
			ChangeMoveType();
		}

		isSelect = true;
	}
}

// ����I��
void Refrigerator::ChangeMoveType()
{
	cout << "�������ꍇ�͂P"		<< endl;
	cout << "���o���ꍇ�͂Q"			<< endl;
	cout << "���g���m�F����ꍇ�͂R"	<< endl;
	cout << "�I������ꍇ��End"		<< endl;
	cout << "����͂��ĉ������B"		<< endl;

	while (mMoveType == MoveType::MOVE_TYPE_NONE)
	{
		string in = "";
		cin >> in;

		if (End(in))
		{
			return;
		}

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