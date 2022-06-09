#include "Refrigerator.h"

Refrigerator::Refrigerator()
	: mMoveType(MoveType::MOVE_TYPE_NONE)
	, mContents()
{
	mName = "冷蔵庫";

	// 初期化
	init();
}

Refrigerator::~Refrigerator()
{
	mContents.clear();
}

// 初期化
void Refrigerator::init()
{
	ElectricAppliances::init();

	// 動作選択
	ChangeMoveType();
}

// 更新
void Refrigerator::Update()
{
	switch (mMoveType)
	{
	case MoveType::MOVE_TYPE_IN:
		// 物を入れる
		AddContent();
		break;
	case MoveType::MOVE_TYPE_OUT:
		// 中身を出す
		PutOutContent();
		break;
	case MoveType::MOVE_TYPE_CONFIRMATION:
		// 中身を確認する
		ConfirmationContent();
		break;
	default:
		break;
	}
}

// 物を入れる
void Refrigerator::AddContent()
{
	// 見やすくする為の空白
	cout << "" << endl;

	cout << "入れる物を入力して下さい。" << endl;

	string content = "";
	cin >> content;

	mContents.emplace_back(content);
	cout << content + "を入れました！" << endl;

	CheckContinue();
}

// 中身を出す
void Refrigerator::PutOutContent()
{
	// 見やすくする為の空白
	cout << "" << endl;

	cout << "出す物を入力して下さい。" << endl;

	string target = "";
	cin >> target;

	auto result = find(mContents.begin(), mContents.end(), target);
	if (result != mContents.end())
	{
		mContents.erase(result);
		cout << target + "を出しました！" << endl;
	}
	else
	{
		cout << "入力された物は冷蔵庫に入っていません。" << endl;
	}

	CheckContinue();
}

// 中身を確認する
void Refrigerator::ConfirmationContent()
{
	// 見やすくする為の空白
	cout << "" << endl;

	cout << "【冷蔵庫の中身】" << endl;

	int size = (int)mContents.size();
	for (int i = 0; i < size; ++i)
	{
		cout << i + 1 << "." + mContents[i] << endl;
	}

	CheckContinue();
}

void Refrigerator::CheckContinue()
{
	// 見やすくする為の空白
	cout << "" << endl;

	switch (mMoveType)
	{
	case Refrigerator::MOVE_TYPE_IN:
		cout << "続けてものを入れますか？" << endl;
		break;
	case Refrigerator::MOVE_TYPE_OUT:
		cout << "続けて中身を出しますか？" << endl;
		break;
	case Refrigerator::MOVE_TYPE_CONFIRMATION:
		cout << "続けて操作を行いますか？" << endl;
		break;
	default:
		return;
	}

	cout << "はい：1" << endl;
	cout << "いいえ：2" << endl;

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

// 動作選択
void Refrigerator::ChangeMoveType()
{
	// 見やすくする為の空白
	cout << "" << endl;

	mMoveType = MoveType::MOVE_TYPE_NONE;

	cout << "どの操作を行いますか？" << endl;
	cout << "物を入れる：1" << endl;
	cout << "中身を出す：2" << endl;
	cout << "中身を確認：3" << endl;

	while (mMoveType == MoveType::MOVE_TYPE_NONE)
	{
		string in = "";
		cin >> in;

		// 終了していれば処理を抜ける
		if (End(in))
		{
			return;
		}

		// 不正な値が入力されていたらやり直し
		int typeNum = ConvertString(in);
		if (typeNum <= MOVE_TYPE_NONE || typeNum >= MOVE_TYPE_NUM)
		{
			cout << "もう一度入力して下さい。" << endl;
			continue;
		}

		mMoveType = (MoveType)typeNum;
	}
}