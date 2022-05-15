#pragma once
#include "ElectricAppliances.h"

// 冷蔵庫
class Refrigerator : public ElectricAppliances
{
public:
	Refrigerator();
	~Refrigerator();

	void update();

private:
	void showContents();

private:
	vector<string> mContents;
};

// 入れたものを中身リストに登録する
// 出したものを中身リストから削除する
// 中身リストの中身を表示する

// 氷を作る
// 氷を取り出す
// 氷の残り個数を表示

// NGワードをテキストファイルから取得
// 閉じるときの冷蔵庫の中身リストを外部テキストに保存
// 開いたときに外部に保存した中身リストを読み込む