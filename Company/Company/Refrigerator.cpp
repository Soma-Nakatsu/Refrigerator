#include "Refrigerator.h"

Refrigerator::Refrigerator()
	: mMoveType(MoveType::MOVE_TYPE_NONE)
	, mContents()
{
	mName = "�①��";

	// ������
	init();
}

Refrigerator::~Refrigerator()
{
	mContents.clear();
}

// ������
void Refrigerator::init()
{
	ElectricAppliances::init();

	// ����I��
	ChangeMoveType();
}

// �X�V
void Refrigerator::Update()
{
	switch (mMoveType)
	{
	case MoveType::MOVE_TYPE_IN:
		// ��������
		AddContent();
		break;
	case MoveType::MOVE_TYPE_OUT:
		// ���g���o��
		PutOutContent();
		break;
	case MoveType::MOVE_TYPE_CONFIRMATION:
		// ���g���m�F����
		ConfirmationContent();
		break;
	default:
		break;
	}
}

// ��������
void Refrigerator::AddContent()
{
	// ���₷������ׂ̋�
	cout << "" << endl;

	cout << "����镨����͂��ĉ������B" << endl;

	string content = "";
	cin >> content;

	mContents.emplace_back(content);
	cout << content + "�����܂����I" << endl;

	CheckContinue();
}

// ���g���o��
void Refrigerator::PutOutContent()
{
	// ���₷������ׂ̋�
	cout << "" << endl;

	cout << "�o��������͂��ĉ������B" << endl;

	string target = "";
	cin >> target;

	auto result = find(mContents.begin(), mContents.end(), target);
	if (result != mContents.end())
	{
		mContents.erase(result);
		cout << target + "���o���܂����I" << endl;
	}
	else
	{
		cout << "���͂��ꂽ���͗①�ɂɓ����Ă��܂���B" << endl;
	}

	CheckContinue();
}

// ���g���m�F����
void Refrigerator::ConfirmationContent()
{
	// ���₷������ׂ̋�
	cout << "" << endl;

	cout << "�y�①�ɂ̒��g�z" << endl;

	int size = (int)mContents.size();
	for (int i = 0; i < size; ++i)
	{
		cout << i + 1 << "." + mContents[i] << endl;
	}

	CheckContinue();
}

void Refrigerator::CheckContinue()
{
	// ���₷������ׂ̋�
	cout << "" << endl;

	switch (mMoveType)
	{
	case Refrigerator::MOVE_TYPE_IN:
		cout << "�����Ă��̂����܂����H" << endl;
		break;
	case Refrigerator::MOVE_TYPE_OUT:
		cout << "�����Ē��g���o���܂����H" << endl;
		break;
	case Refrigerator::MOVE_TYPE_CONFIRMATION:
		cout << "�����đ�����s���܂����H" << endl;
		break;
	default:
		return;
	}

	cout << "�͂��F1" << endl;
	cout << "�������F2" << endl;

	bool isSelect = false;
	while (!isSelect)
	{
		string select = "";
		cin >> select;

		if (select != "1" && select != "2")
		{
			continue;
		}

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
	// ���₷������ׂ̋�
	cout << "" << endl;

	mMoveType = MoveType::MOVE_TYPE_NONE;

	cout << "�ǂ̑�����s���܂����H" << endl;
	cout << "��������F1" << endl;
	cout << "���g���o���F2" << endl;
	cout << "���g���m�F�F3" << endl;

	while (mMoveType == MoveType::MOVE_TYPE_NONE)
	{
		string in = "";
		cin >> in;

		// �I�����Ă���Ώ����𔲂���
		if (End(in))
		{
			return;
		}

		// �s���Ȓl�����͂���Ă������蒼��
		int typeNum = ConvertString(in);
		if (typeNum <= MOVE_TYPE_NONE || typeNum >= MOVE_TYPE_NUM)
		{
			cout << "������x���͂��ĉ������B" << endl;
			continue;
		}

		mMoveType = (MoveType)typeNum;
	}
}