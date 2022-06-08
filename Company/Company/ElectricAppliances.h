#pragma once
#include "Utility.h"

// 電化製品基底クラス
class ElectricAppliances
{
public:
	ElectricAppliances();
	~ElectricAppliances();

	virtual void Update();

	void FirstProcess();

	void Start();
	bool End(string in);

	bool ISEnd() { return mIsEnd; }

protected:
	void ViewStartString();

	bool mIsEnd;

	string mName;
};