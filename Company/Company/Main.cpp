#include "Include Heders.h"
#include "Refrigerator.h"

int main()
{
	Refrigerator refrigerator;

	while (!refrigerator.ISEnd())
	{
		refrigerator.update();
	}

	std::cout << "�v���O�����I��" << std::endl;
};