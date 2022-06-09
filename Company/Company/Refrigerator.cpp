#include "Refrigerator.h"

// 冷蔵庫で使用する定数
static const string NAME		= "冷蔵庫";
static const string FILE_PATH	= "../Resources/Refrigerator.txt";

Refrigerator::Refrigerator()
	: mMoveType(MoveType::MOVE_TYPE_NONE)
	, mContents()
{
	mName = NAME;

	// 初期化
	init();
}

Refrigerator::~Refrigerator()
{
	// 今のmContentsの内容をテキストに書き込む
	WriteContents();
	
	mContents.clear();
}

// 初期化
void Refrigerator::init()
{
	// テキストファイルからのセットアップに失敗したら終了する
	if (!SetupContents())
	{
		cout << "セットアップに失敗。終了します。" << endl;
		mIsEnd = true;
		return;
	}

	ElectricAppliances::init();

	// 動作選択
	ChangeMoveType();
}

// 冷蔵庫の中身テキストを開く
bool Refrigerator::SetupContents()
{
	ifstream file(FILE_PATH);
	if (!file)
	{
		cout << "ファイル読み込み失敗" << endl;
		return false;
	}

	cout << "ファイル読み込み成功" << endl;

	// 内容をmContentsに格納
	string content = "";
	while (getline(file, content))
	{
		mContents.emplace_back(content);
	}

	return true;
}

// 今のmContentsの内容をテキストに書き込む
void Refrigerator::WriteContents()
{
	ofstream file(FILE_PATH);
	if (!file)
	{
		return;
	}

	// mContentsの内容をテキストに書き込む
	for (const auto& content : mContents)
	{
		file << content << endl;
	}

	cout << "ファイルへの書き込み終了" << endl;
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
		ConfirmationContents();
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

	string in = "";
	cin >> in;

	mContents.emplace_back(in);
	cout << in + "を入れました！" << endl;

	CheckContinue();
}

// 中身を出す
void Refrigerator::PutOutContent()
{
	// 見やすくする為の空白
	cout << "" << endl;

	cout << "出す物を入力して下さい。" << endl;

	string in = "";
	cin >> in;

	auto content = find(mContents.begin(), mContents.end(), in);
	if (content != mContents.end())
	{
		mContents.erase(content);
		cout << in + "を出しました！" << endl;
	}
	else
	{
		cout << "入力された物は冷蔵庫に入っていません。" << endl;
	}

	CheckContinue();
}

// 中身を確認する
void Refrigerator::ConfirmationContents()
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
	cout << "終了する　：End" << endl;

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