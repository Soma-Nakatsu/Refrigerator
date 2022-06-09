#include "Utility.h"
#include "Refrigerator.h"

int main(void)
{
	Refrigerator refrigerator;

	while (!refrigerator.ISEnd())
	{
		refrigerator.Update();
	}

	std::cout << "ƒvƒƒOƒ‰ƒ€I—¹" << std::endl;
};