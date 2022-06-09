#include "ElectricAppliances.h"

ElectricAppliances::ElectricAppliances()
	: mIsEnd(false)
	, mName("")
{
}

ElectricAppliances::~ElectricAppliances()
{
}

// 初期化
void ElectricAppliances::init()
{
	ViewStartString();
	Start();
}

// 更新
void ElectricAppliances::Update()
{
}

// 開始判定処理
void ElectricAppliances::Start()
{
	bool isStart = false;
	while (!isStart)
	{
		string startText[2];
		startText[0] = "Start";
		startText[1] = "start";

		string in = "";
		cin >> in;

		if (in != startText[0] && in != startText[1])
		{
			continue;
		}

		isStart = true;
	}

	cout << mName + "を起動しました。終了する場合はEndと入力して下さい。" << endl;
}

// 終了判定処理
bool ElectricAppliances::End(string in)
{
	string endText[2];
	endText[0] = "End";
	endText[1] = "end";

	if (in == endText[0] || in == endText[1])
	{
		mIsEnd = true;
	}

	return mIsEnd;
}

// 開始時に表示する文言表示
void ElectricAppliances::ViewStartString()
{
	cout << mName + "を起動する場合はStartと入力して下さい。" << endl;
}