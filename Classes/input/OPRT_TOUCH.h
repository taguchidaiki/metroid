#pragma once
#include "OPRT.h"

struct OPRT_TOUCH :public OPRT
{
	OPRT_TOUCH(cocos2d::Node& sp);
	~OPRT_TOUCH();

	//入力タイプ::タッチ
	OPRT_TYPE GetOprtType() override { return OPRT_TYPE::TOUCH;  };

	void Init(cocos2d::Node& sp) override;
	void Update() override;

private:
	std::pair<cocos2d::Point, cocos2d::Point> _touchPoint;
	cocos2d::Vec2 _vec;
	bool _moveFlag;
	int count = 0;
};

