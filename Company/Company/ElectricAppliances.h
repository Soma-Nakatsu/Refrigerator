#pragma once
#include "Include Heders.h"

// �d�����i���N���X
class ElectricAppliances
{
public:
	ElectricAppliances();
	~ElectricAppliances();

	virtual void Update();

	void Start();
	void End();

	bool IsOn() { return isOn; }
	bool ISEnd() { return isEnd; }

protected:
	void ViewStartString();

	bool isOn;
	bool isEnd;

	string name;
};