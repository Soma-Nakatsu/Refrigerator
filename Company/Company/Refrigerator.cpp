#include "Refrigerator.h"

Refrigerator::Refrigerator()
	: mMoveType(MoveType::MOVE_TYPE_NONE)
	, mContents()
{
	mName = "冷蔵庫";

	FirstProcess();

	// 動作選択
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
		// 物を入れる
		AddContent();
		break;
	case Refrigerator::MoveType::MOVE_TYPE_OUT:
		// 中身を出す
		PutOutContent();
		break;
	case Refrigerator::MoveType::MOVE_TYPE_CONFIRMATION:
		// 中身を確認する
		ConfirmationContent();
		break;

	case Refrigerator::MoveType::MOVE_TYPE_NONE:
	
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

// 物を入れる
void Refrigerator::AddContent()
{
	cout << "入れるものを入力してください。" << endl;

	string content = "";
	cin >> content;

	mContents.emplace_back(content);
	cout << content + "を入れました！" << endl;

	cout << "続けてものを入れますか？" << endl;
	cout << "はい：1" << endl;
	cout << "いいえ：２" << endl;

	bool isSelect = false;
	while (!isSelect)
	{
		string select = "";
		cin >> select;

		if (select != "1" && select != "2")
		{
			continue;
		}

		// 続けてものを入れない場合は動作選択へ
		if (select == "2")
		{
			ChangeMoveType();
		}

		isSelect = true;
	}
}

// 動作選択
void Refrigerator::ChangeMoveType()
{
	cout << "物入れる場合は１"		<< endl;
	cout << "物出す場合は２"			<< endl;
	cout << "中身を確認する場合は３"	<< endl;
	cout << "終了する場合はEnd"		<< endl;
	cout << "を入力して下さい。"		<< endl;

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