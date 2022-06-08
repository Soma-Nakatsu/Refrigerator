#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace Utility
{
	// 配列の要素数をカウントする
	template<typename T, size_t SIZE>
	static int GetArreySize(const T(&/*arrey*/)[SIZE])
	{ 
		// arreyの要素数を返す
		return (int)SIZE;
	}
}