#include "Utility.h"
#include "Refrigerator.h"

int main(void)
{
	Refrigerator refrigerator;

	while (!refrigerator.ISEnd())
	{
		refrigerator.Update();
	}

	// ���₷������ׂ̋�
	cout << "" << endl;
	std::cout << "�v���O�����I��" << std::endl;
};