#include "Refrigerator.h"

Refrigerator::Refrigerator()
{
	name = "�①��";
	ViewStartString();
}

Refrigerator::~Refrigerator()
{
}

void Refrigerator::update()
{
	if (!isOn)
	{
		Start();
		return;
	}

	string in = "";
	cout << "�������܂����H" << endl;
	cin >> in;
	cout << in + "�����܂����I" << endl;

	End();
}
