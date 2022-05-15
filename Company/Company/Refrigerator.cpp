#include "Refrigerator.h"

Refrigerator::Refrigerator()
{
	mName = "冷蔵庫";
	mStartType = StartType::Open;

	FirstProcess();
}

Refrigerator::~Refrigerator()
{
}

void Refrigerator::update()
{
	string in = "";
	cout << "入れるものを入力してください。Nakamiと入力すると中身が確認できます。" << endl;
	cin >> in;

	End(in);

	// 終了入力がされていた場合は何もしない
	if (isEnd)
	{
		return;
	}

	if (in == "Nakami" || in == "nakami")
	{
		showContents();
	}
	else
	{
		cout << in + "を入れました！" << endl;
		mContents.emplace_back(in);
	}
}

void Refrigerator::showContents()
{
	cout << "冷蔵庫の中身：";

	for (auto content : mContents)
	{
		cout << content  +", ";
	}

	cout << "\n";
}