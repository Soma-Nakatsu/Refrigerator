#include "ElectricAppliances.h"

ElectricAppliances::ElectricAppliances()
	: mIsEnd(false)
	, mName("")
{
}

ElectricAppliances::~ElectricAppliances()
{
}

void ElectricAppliances::Update()
{
}

void ElectricAppliances::FirstProcess()
{
	ViewStartString();
	Start();
}

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

	cout << mName + "���N�����܂����B�I������ꍇ��End�Ɠ��͂��ĉ������B" << endl;
}

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

void ElectricAppliances::ViewStartString()
{
	cout << mName + "���N������ꍇ��Start�Ɠ��͂��ĉ������B" << endl;
}