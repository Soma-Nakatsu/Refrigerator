#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace Utility
{
	// �z��̗v�f�����J�E���g����
	template<typename T, size_t SIZE>
	static int GetArreySize(const T(&/*arrey*/)[SIZE])
	{ 
		// arrey�̗v�f����Ԃ�
		return (int)SIZE;
	}
}