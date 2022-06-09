#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// 配列の要素数をカウントする
template<typename T, size_t size>
inline int GetArreySize(const T(&/*arrey*/)[size])
{
	// arreyの要素数を返す
	return (int)size;
}

// 文字列を数値に変換
inline int ConvertString(string str)
{
	return atoi(str.c_str());
}
inline int ConvertString(const char* str)
{
	return atoi(str);
}