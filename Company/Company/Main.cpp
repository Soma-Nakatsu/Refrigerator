#include "Include Heders.h"
#include "Refrigerator.h"

int main()
{
	Refrigerator refrigerator;

	while (!refrigerator.ISEnd())
	{
		refrigerator.update();
	}

	std::cout << "ƒvƒƒOƒ‰ƒ€I—¹" << std::endl;
};