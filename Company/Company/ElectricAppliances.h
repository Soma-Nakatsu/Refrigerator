#pragma once
#include "Utility.h"

// 電化製品基底クラス
class ElectricAppliances
{
public:
	// コンストラクタ/デストラクタ
	ElectricAppliances();
	~ElectricAppliances();

	// 更新
	virtual void Update();

	bool ISEnd() { return mIsEnd; }

protected:
	// 初期化
	virtual void init();

	// 開始判定処理
	void Start();
	// 終了判定処理
	bool End(string in);

	// 開始時に表示する文言表示
	void ViewStartString();

protected:
	bool	mIsEnd;	// 終了するか？
	string	mName;	// 設定した名前
};