#include "Refrigerator.h"

Refrigerator::Refrigerator()
{
	name = "冷蔵庫";
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
	cout << "何を入れますか？" << endl;
	cin >> in;
	cout << in + "を入れました！" << endl;

	End();
}
