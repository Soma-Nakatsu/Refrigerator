#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// �z��̗v�f�����J�E���g����
template<typename T, size_t size>
inline int GetArreySize(const T(&/*arrey*/)[size])
{
	// arrey�̗v�f����Ԃ�
	return (int)size;
}

// ������𐔒l�ɕϊ�
inline int ConvertString(string str)
{
	return atoi(str.c_str());
}
inline int ConvertString(const char* str)
{
	return atoi(str);
}