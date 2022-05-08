#pragma once
#include "ElectricAppliances.h"

// 冷蔵庫
class Refrigerator : public ElectricAppliances
{
public:
	Refrigerator();
	~Refrigerator();

	void update();
};

// 物を入れる
// 物を出す
// 中身の確認
// 氷を作る
// 氷を取り出す
// 氷の残り個数を表示
// NGワードをテキストファイルから取得
// 閉じる
// 閉じるときの冷蔵庫の中身を外部テキストに保存
