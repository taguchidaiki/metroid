#pragma once
#include "OPRT.h"

struct OPRT_KEY :public OPRT
{
	
	OPRT_KEY(cocos2d::Node& sp);

	//初期化関数
	void Init(cocos2d::Node& sp) override;

	//入力タイプを返す
	OPRT_TYPE GetOprtType(void) override { return OPRT_TYPE::KEY; };

	//アップデート関数
	void Update() override;

};

