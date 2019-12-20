#pragma once
#include "OPRT.h"

struct OPRT_KEY :public OPRT
{
	
	OPRT_KEY(cocos2d::Node& sp);
	~OPRT_KEY() {};

	//初期化関数
	void Init(cocos2d::Node& sp) override;

	//入力タイプを返す
	OPRT_TYPE GetOprtType(void) override { return OPRT_TYPE::KEY; };

	//アップデート関数
	void Update() override;

private:

	//cocos2dxのキー情報から必要なものだけ回収したテーブル
	KEY_TYPE _keyTbl[static_cast<int>(PTN::MAX)] = {
		KEY_TYPE::KEY_SPACE,
		KEY_TYPE::KEY_RIGHT_ARROW,
		KEY_TYPE::KEY_LEFT_ARROW,
		KEY_TYPE::KEY_NONE
	};
};

