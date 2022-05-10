#include "Refrigerator.h"

Refrigerator::Refrigerator()
{
	name = "—â‘ ŒÉ";
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
	cout << "‰½‚ð“ü‚ê‚Ü‚·‚©H" << endl;
	cin >> in;
	cout << in + "‚ð“ü‚ê‚Ü‚µ‚½I" << endl;

	End();
}
