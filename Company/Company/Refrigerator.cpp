#include "Refrigerator.h"

Refrigerator::Refrigerator()
{
	mName = "�①��";
	mStartType = StartType::Open;

	FirstProcess();
}

Refrigerator::~Refrigerator()
{
}

void Refrigerator::update()
{
	string in = "";
	cout << "�������̂���͂��Ă��������BNakami�Ɠ��͂���ƒ��g���m�F�ł��܂��B" << endl;
	cin >> in;

	End(in);

	// �I�����͂�����Ă����ꍇ�͉������Ȃ�
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
		cout << in + "�����܂����I" << endl;
		mContents.emplace_back(in);
	}
}

void Refrigerator::showContents()
{
	cout << "�①�ɂ̒��g�F";

	for (auto content : mContents)
	{
		cout << content  +", ";
	}

	cout << "\n";
}