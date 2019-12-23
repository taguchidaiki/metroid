#pragma once
#include "OPRT.h"

struct OPRT_TOUCH :public OPRT
{
	OPRT_TOUCH(cocos2d::Node& sp, cocos2d::Layer& layer);
	~OPRT_TOUCH();

	//入力タイプ::タッチ
	OPRT_TYPE GetOprtType() override { return OPRT_TYPE::TOUCH;  };

	void Init(cocos2d::Node& sp) override;
	void Update() override;

private:
	std::pair<cocos2d::Point, cocos2d::Point> _touchPoint;

	//cocos2dxのキー情報から必要なものだけ回収したテーブル
	cocos2d::Node* _touchTbl[static_cast<int>(PTN::MAX)];

};

