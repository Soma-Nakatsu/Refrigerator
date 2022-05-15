#pragma once
#include "Include Heders.h"

// 電化製品基底クラス
class ElectricAppliances
{
public:
	enum class StartType
	{
		None = 0,	// None
		Open,		// Opne, Close
		On,			// On, Off
	};

public:
	ElectricAppliances();
	~ElectricAppliances();

	virtual void Update();

	void FirstProcess();

	void Start();
	void End(string in);

	bool IsOn() { return isOn; }
	bool ISEnd() { return isEnd; }

protected:
	void ViewStartString();

	bool isOn;
	bool isEnd;

	string mName;
	StartType mStartType;
};