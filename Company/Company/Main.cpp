#include "Utility.h"
#include "Refrigerator.h"

int main(void)
{
	Refrigerator refrigerator;

	while (!refrigerator.ISEnd())
	{
		refrigerator.Update();
	}

	// 見やすくする為の空白
	cout << "" << endl;
	std::cout << "プログラム終了" << std::endl;
};