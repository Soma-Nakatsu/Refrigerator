#include "Refrigerator.h"

// �①�ɂŎg�p����萔
static const string NAME		= "�①��";
static const string FILE_PATH	= "../Resources/Refrigerator.txt";

Refrigerator::Refrigerator()
	: mMoveType(MoveType::MOVE_TYPE_NONE)
	, mContents()
{
	mName = NAME;

	// ������
	init();
}

Refrigerator::~Refrigerator()
{
	// ����mContents�̓��e���e�L�X�g�ɏ�������
	WriteContents();
	
	mContents.clear();
}

// ������
void Refrigerator::init()
{
	// �e�L�X�g�t�@�C������̃Z�b�g�A�b�v�Ɏ��s������I������
	if (!SetupContents())
	{
		cout << "�Z�b�g�A�b�v�Ɏ��s�B�I�����܂��B" << endl;
		mIsEnd = true;
		return;
	}

	ElectricAppliances::init();

	// ����I��
	ChangeMoveType();
}

// �①�ɂ̒��g�e�L�X�g���J��
bool Refrigerator::SetupContents()
{
	ifstream file(FILE_PATH);
	if (!file)
	{
		cout << "�t�@�C���ǂݍ��ݎ��s" << endl;
		return false;
	}

	cout << "�t�@�C���ǂݍ��ݐ���" << endl;

	// ���e��mContents�Ɋi�[
	string content = "";
	while (getline(file, content))
	{
		mContents.emplace_back(content);
	}

	return true;
}

// ����mContents�̓��e���e�L�X�g�ɏ�������
void Refrigerator::WriteContents()
{
	ofstream file(FILE_PATH);
	if (!file)
	{
		return;
	}

	// mContents�̓��e���e�L�X�g�ɏ�������
	for (const auto& content : mContents)
	{
		file << content << endl;
	}

	cout << "�t�@�C���ւ̏������ݏI��" << endl;
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
		ConfirmationContents();
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

	string in = "";
	cin >> in;

	mContents.emplace_back(in);
	cout << in + "�����܂����I" << endl;

	CheckContinue();
}

// ���g���o��
void Refrigerator::PutOutContent()
{
	// ���₷������ׂ̋�
	cout << "" << endl;

	cout << "�o��������͂��ĉ������B" << endl;

	string in = "";
	cin >> in;

	auto content = find(mContents.begin(), mContents.end(), in);
	if (content != mContents.end())
	{
		mContents.erase(content);
		cout << in + "���o���܂����I" << endl;
	}
	else
	{
		cout << "���͂��ꂽ���͗①�ɂɓ����Ă��܂���B" << endl;
	}

	CheckContinue();
}

// ���g���m�F����
void Refrigerator::ConfirmationContents()
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
		string in = "";
		cin >> in;

		if (in != "1" && in != "2")
		{
			continue;
		}

		if (in == "2")
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
	cout << "�I������@�FEnd" << endl;

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