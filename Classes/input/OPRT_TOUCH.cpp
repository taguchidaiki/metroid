#include "OPRT_TOUCH.h"

OPRT_TOUCH::OPRT_TOUCH(cocos2d::Node& sp, const cocos2d::Layer& layer)
{	
	for (int i = 0; i < static_cast<int>(PTN::MAX); i++)
	{
		std::get<0>(_input[i]) = static_cast<PTN>(i);
		std::get<2>(_input[i]) = false;
	}
	Init(sp);
}

OPRT_TOUCH::~OPRT_TOUCH()
{
}

void OPRT_TOUCH::Init(cocos2d::Node & sp)
{
	auto _ctlTouch = cocos2d::EventListenerTouchOneByOne::create();
	_ctlTouch->onTouchBegan = [this](cocos2d::Touch *touch, cocos2d::Event* event)
	{
		_touchPoint.first = touch->getLocation();
		std::get<2>(_input[static_cast<int>(PTN::NON_KEY)]) = false;
		return true;
	};

	_ctlTouch->onTouchEnded = [this](cocos2d::Touch *touch, cocos2d::Event* event)
	{
		_touchPoint.second = touch->getLocation();
		std::get<2>(_input[static_cast<int>(PTN::NON_KEY)]) = true;
		return true;
	};

	//cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(_ctlTouch, sp);
	sp.getEventDispatcher()->addEventListenerWithSceneGraphPriority(_ctlTouch, &sp);
}

void OPRT_TOUCH::Update()
{
	//キー情報の新旧更新処理
	for (int i = 0; i < static_cast<int>(PTN::MAX); i++)
	{
		std::get<1>(_input[i]) = std::get<2>(_input[i]);
	}
}
