#include "OPRT_TOUCH.h"

OPRT_TOUCH::OPRT_TOUCH(cocos2d::Node& sp, cocos2d::Layer& layer)
{	
	for (int i = 0; i < static_cast<int>(PTN::MAX); i++)
	{
		std::get<0>(_key[i]) = static_cast<PTN>(i);
		std::get<2>(_key[i]) = false;
		if (i < layer.getChildrenCount())
		{
			_touchTbl[i] = layer.getChildren().at(i);
		}
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

		for (int i = 0; i < static_cast<int>(PTN::NON_KEY); i++)
		{
			//タッチポイントとスプライトの当たり判定
			if (_touchTbl[i]->getBoundingBox().containsPoint(_touchPoint.first))
			{
				std::get<2>(_key[i]) = true;
			}

		}

		std::get<2>(_key[static_cast<int>(PTN::NON_KEY)]) = false;
		return true;
	};

	_ctlTouch->onTouchEnded = [this](cocos2d::Touch *touch, cocos2d::Event* event)
	{
		_touchPoint.second = touch->getLocation();
		for (int i = 0; i < static_cast<int>(PTN::NON_KEY); i++)
		{
			if (_touchTbl[i]->getBoundingBox().containsPoint(_touchPoint.second))
			{
				std::get<2>(_key[i]) = false;
			}
		}
		std::get<2>(_key[static_cast<int>(PTN::NON_KEY)]) = true;
		return true;
	};

	sp.getEventDispatcher()->addEventListenerWithSceneGraphPriority(_ctlTouch, &sp);
}

void OPRT_TOUCH::Update()
{
	//キー情報の新旧更新処理
	for (int i = 0; i < static_cast<int>(PTN::MAX); i++)
	{
		std::get<1>(_key[i]) = std::get<2>(_key[i]);
	}
}
