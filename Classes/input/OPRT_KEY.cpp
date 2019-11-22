#include "OPRT_KEY.h"

OPRT_KEY::OPRT_KEY(cocos2d::Node& sp)
{
	for (int i = 0; i < static_cast<int>(PTN::MAX); i++)
	{
		std::get<0>(_key[i]) = static_cast<PTN>(i);
		std::get<2>(_key[i]) = false;
	}
	Init(sp);
}

void OPRT_KEY::Init(cocos2d::Node& sp)
{
	//キーが押されたときのイベント情報
	auto ctlKey = cocos2d::EventListenerKeyboard::create();
	ctlKey->onKeyPressed = [this](cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) {
		for (int i = 0; i < static_cast<int>(PTN::MAX); i++)
		{
			if (keyCode == _keyTbl[i])
			{
				std::get<2>(_key[i]) = true;
			}

		}
		return true;
	};

	//キーから離れた時のイベント情報
	ctlKey->onKeyReleased = [this](cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) {
		for (int i = 0; i < static_cast<int>(PTN::MAX); i++)
		{
			if (keyCode == _keyTbl[i])
			{
				std::get<2>(_key[i]) = false;
			}
		}
		return true;
	};

	cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(ctlKey, &sp);
}

void OPRT_KEY::Update()
{
	//キー情報の新旧更新処理
	for(int i = 0; i < static_cast<int>(PTN::MAX);i++)
	{
		std::get<1>(_key[i]) = std::get<2>(_key[i]);
	}

	//_dirの分回してその移動判定がtrueの方向にだけ動かす
	//for (auto dir : _dir)
	//{
	//	if (dir.second == true)
	//	{
	//		//sp->setPosition(sp->getPosition() + dir.first * sp->speed());
	//		auto action = cocos2d::MoveBy::create(1 / 60.0f, dir.first * sp.speed());
	//		sp.runAction(action);
	//	}
	//}
}
