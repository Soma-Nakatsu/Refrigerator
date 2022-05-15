#include "ElectricAppliances.h"

ElectricAppliances::ElectricAppliances()
	: isOn(false)
	, isEnd(false)
	, mName("")
	, mStartType(StartType::None)
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
	while (!isOn)
	{
		string startText[2];
		switch (mStartType)
		{
		case ElectricAppliances::StartType::Open:
			startText[0] = "Open";
			startText[1] = "open";
			break;

		case ElectricAppliances::StartType::None:
		default:
			startText[0] = "Start";
			startText[1] = "start";
			break;
		}

		string in = "";
		cin >> in;

		if (in != startText[0] && in != startText[1])
		{
			continue;
		}

		isOn = true;
	}

	string endText;
	switch (mStartType)
	{
	case ElectricAppliances::StartType::Open:
		endText = "Close";
		break;

	case ElectricAppliances::StartType::None:
	default:
		endText = "End";
		break;
	}

	cout << mName + "を起動しました。終了する場合は" + endText + "と入力して下さい。" << endl;
}

void ElectricAppliances::End(string in)
{
	string endText[2];
	switch (mStartType)
	{
	case ElectricAppliances::StartType::Open:
		endText[0] = "Close";
		endText[1] = "close";
		break;

	case ElectricAppliances::StartType::None:
	default:
		endText[0] = "End";
		endText[1] = "end";
		break;
	}

	if (in != endText[0] && in != endText[1])
	{
		return;
	}

	isEnd = true;
}

void ElectricAppliances::ViewStartString()
{
	string text = "";
	switch (mStartType)
	{
	case ElectricAppliances::StartType::Open:
		text = "Open";
		break;

	case ElectricAppliances::StartType::None:
	default:
		text = "Start";
		break;
	}

	cout << mName + "を起動する場合は" + text + "と入力して下さい。" << endl;
}