#include "Utility.h"
#include "Refrigerator.h"

int main(void)
{
	Refrigerator refrigerator;

	while (!refrigerator.ISEnd())
	{
		refrigerator.Update();
	}

	std::cout << "�v���O�����I��" << std::endl;
};