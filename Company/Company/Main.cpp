#include "Refrigerator.h"

int main()
{
	Refrigerator refrigerator;

	while (!refrigerator.ISEnd())
	{
		refrigerator.update();
	}

	std::cout << "プログラム終了" << std::endl;
};