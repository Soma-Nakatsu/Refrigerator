#include "Utility.h"
#include "Refrigerator.h"

int main()
{
	Refrigerator refrigerator;

	while (!refrigerator.ISEnd())
	{
		refrigerator.Update();
	}

	std::cout << "プログラム終了" << std::endl;
};