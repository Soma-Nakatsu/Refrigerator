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
	// ���ɋN�����Ă��鎞�͉������Ȃ�
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

	cout << name + "�N�����܂����B" << endl;
	cout << "�I������ꍇ��End�Ɠ��͂��ĉ������B" << endl;
}

void ElectricAppliances::End()
{
	// ���N�����͉������Ȃ�
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
	cout << name + "���N������ꍇ��Start�Ɠ��͂��ĉ������B" << endl;
}