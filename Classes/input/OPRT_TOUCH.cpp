#include "OPRT_TOUCH.h"

OPRT_TOUCH::OPRT_TOUCH(cocos2d::Node& sp)
{	
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
		return true;
	};

	_ctlTouch->onTouchEnded = [this](cocos2d::Touch *touch, cocos2d::Event* event)
	{
		_touchPoint.second = touch->getLocation();
		_moveFlag = true;
		return true;
	};

	//cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(_ctlTouch, sp);
	sp.getEventDispatcher()->addEventListenerWithSceneGraphPriority(_ctlTouch, &sp);
}

void OPRT_TOUCH::Update()
{

	if (_moveFlag)
	{
		//‚Æ‚è‚ ‚¦‚¸“K“–‚È’l
		_vec = (_touchPoint.second - _touchPoint.first) / 10;
		//sp.setPosition(sp.getPosition() + _vec);
		count++;
		if (count >= 10)
		{
			count = 0;
			_vec = cocos2d::Vec2(0, 0);
			_moveFlag = false;
		}
	}
}
