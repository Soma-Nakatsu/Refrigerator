#include "Refrigerator.h"

Refrigerator::Refrigerator()
{
	name = "�①��";
	ViewStartString();
	Start();
}

Refrigerator::~Refrigerator()
{
}

void Refrigerator::update()
{
	if (!isOn)
	{
		
		return;
	}

	string in = "";
	cout << "�������܂����H" << endl;
	cin >> in;
	cout << in + "�����܂����I" << endl;

	End();
}
