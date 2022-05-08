#include "ElectricAppliances.h"

ElectricAppliances::ElectricAppliances()
	: isOn(false)
	, isEnd(false)
	, name("")
{
}

ElectricAppliances::~ElectricAppliances()
{
}

void ElectricAppliances::Update()
{
}

void ElectricAppliances::Start()
{
	// 既に起動している時は何もしない
	if (isOn)
	{
		return;
	}

	string in = "";
	cin >> in;

	if (in != "Start")
	{
		return;
	}

	isOn = true;

	cout << name + "起動しました。" << endl;
	cout << "終了する場合はEndと入力して下さい。" << endl;
}

void ElectricAppliances::End()
{
	// 未起動時は何もしない
	if (!isOn)
	{
		return;
	}

	string in = "";
	cin >> in;

	if (in != "End")
	{
		return;
	}

	isEnd = true;
}

void ElectricAppliances::ViewStartString()
{
	cout << name + "を起動する場合はStartと入力して下さい。" << endl;
}