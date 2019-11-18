#include "OPRT_KEY.h"

OPRT_KEY::OPRT_KEY(cocos2d::Node& sp)
{
	/*_dir[static_cast<int>(DIR::UP)].first = cocos2d::Vec2(0, 1);
	_dir[static_cast<int>(DIR::DOWN)].first = cocos2d::Vec2(0, -1);
	_dir[static_cast<int>(DIR::RIGHT)].first = cocos2d::Vec2(1, 0);
	_dir[static_cast<int>(DIR::LEFT)].first = cocos2d::Vec2(-1, 0);*/

	for (int i = 0; i < static_cast<int>(KEY::MAX); i++)
	{
		std::get<0>(_key[i]) = static_cast<KEY>(i);
		std::get<2>(_key[i]) = false;
	}
	Init(sp);
}

void OPRT_KEY::Init(cocos2d::Node& sp)
{
	//�L�[�������ꂽ�Ƃ��̃C�x���g���
	auto ctlKey = cocos2d::EventListenerKeyboard::create();
	ctlKey->onKeyPressed = [this](cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) {
		for (int i = 0; i < static_cast<int>(KEY::MAX); i++)
		{
			if (keyCode == _keyTbl[i])
			{
				std::get<2>(_key[i]) = true;
			}

		}
		return true;
	};

	//�L�[���痣�ꂽ���̃C�x���g���
	ctlKey->onKeyReleased = [this](cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) {
		for (int i = 0; i < static_cast<int>(KEY::MAX); i++)
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
	//�L�[���̐V���X�V����
	for(int i = 0; i < static_cast<int>(KEY::MAX);i++)
	{
		std::get<1>(_key[i]) = std::get<2>(_key[i]);
	}

	//_dir�̕��񂵂Ă��̈ړ����肪true�̕����ɂ���������
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
