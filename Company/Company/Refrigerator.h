#pragma once
#include "ElectricAppliances.h"

// 冷蔵庫
class Refrigerator : public ElectricAppliances
{
public:
	enum MoveType
	{
		MOVE_TYPE_NONE = 0,		// 未動作
		MOVE_TYPE_IN,			// 動作タイプ：物を入れる
		MOVE_TYPE_OUT,			// 動作タイプ：中身を出す
		MOVE_TYPE_CONFIRMATION,	// 動作タイプ：中身を確認

		MOVE_TYPE_NUM
	};

public:
	// コンストラクタ/デストラクタ
	Refrigerator();
	~Refrigerator();

	// 更新
	void Update() override;

private:
	// 初期化
	void init() override;

	// テキストファイルからmContentsの内容を設定
	bool SetupContents();
	// 今のmContentsの内容をテキストに書き込む
	void WriteContents();

	// 物を入れる
	void AddContent();
	// 中身を出す
	void PutOutContent();
	// 中身を確認する
	void ConfirmationContents();

	// 続けて操作を行うかのチェック
	void CheckContinue();
	// 動作選択
	void ChangeMoveType();

private:
	MoveType		mMoveType;		// 動作タイプ
	vector<string>	mContents;		// 冷蔵庫の中身リスト
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