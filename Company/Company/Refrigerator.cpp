#include "Refrigerator.h"

Refrigerator::Refrigerator()
	: mMoveType(MoveType::MOVE_TYPE_NONE)
	, mContents()
{
	mName = "冷蔵庫";

	FirstProcess();

	// 動作タイプ設定
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
		message = "入れるものを入力して下さい。";
		break;
	case Refrigerator::MoveType::MOVE_TYPE_OUT:
		message = "出すものを入力して下さい。";
		break;

	case Refrigerator::MoveType::MOVE_TYPE_NONE:
	case Refrigerator::MoveType::MOVE_TYPE_CONFIRMATION:
	default:
		break;
	}


	cout << "入れるものを入力してください。Nakamiと入力すると中身が確認できます。" << endl;


	string in = "";
	cin >> in;

	// 終了入力がされていた場合は何もしない
	if (End(in))
	{
		return;
	}

	// 本実装

	if (in == "Nakami" || in == "nakami")
	{
		ShowContents();
	}
	else
	{
		cout << in + "を入れました！" << endl;
		mContents.emplace_back(in);
	}
}

// 動作タイプの変更
void Refrigerator::ChangeMoveType()
{
	cout << "物入れる場合は１" << endl;
	cout << "物出す場合は２" << endl;
	cout << "中身を確認する場合は３" << endl;
	cout << "を入力して下さい。" << endl;

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

// 冷蔵庫の中身を表示
void Refrigerator::ShowContents()
{
	cout << "【冷蔵庫の中身】" << endl;

	auto size = (int)mContents.size();
	for (int i = 0; i < size; ++i)
	{
		cout << i + 1 << "." + mContents[i] << endl;
	}
}