#include "Utility.h"
#include "Refrigerator.h"

int main(void)
{
	Refrigerator refrigerator;

	while (!refrigerator.ISEnd())
	{
		refrigerator.Update();
	}

	// Œ©‚â‚·‚­‚·‚éˆ×‚Ì‹ó”’
	cout << "" << endl;
	std::cout << "ƒvƒƒOƒ‰ƒ€I—¹" << std::endl;
};