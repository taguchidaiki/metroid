#pragma once
#include "cocos2d.h"
#include <map>
#include <array>

#define KEY_TYPE cocos2d::EventKeyboard::KeyCode

enum class PTN
{
	SHOT,
	JUMP,
	M_RIGHT,
	M_LEFT,
	MAX
};

enum class OPRT_TYPE
{
	KEY,
	TOUCH,
	MAX
};

struct OPRT
{
	OPRT(){};
	virtual ~OPRT() {};

	virtual void Init(cocos2d::Node& sp) = 0;
	virtual OPRT_TYPE GetOprtType(void) = 0;
	virtual void Update() = 0;

	//get�֐�
	std::array<std::tuple<PTN,bool,bool>, static_cast<int>(PTN::MAX)> key(void) { return _key; };
	
protected:
	//�ړ������̏�� _dir[�ړ������̃x�N�g��,���̕����Ɉړ����邩�ǂ���]
	//std::array<std::pair<cocos2d::Vec2,bool>, static_cast<int>(DIR::MAX)> _key;

	//�L�[�̓��͏��@_dir[�L�[�̏��] first old��� second now���
	std::array<std::tuple<PTN, bool, bool>, static_cast<int>(PTN::MAX)> _key;

	//cocos2dx�̃L�[��񂩂�K�v�Ȃ��̂�����������e�[�u��
	KEY_TYPE _keyTbl[static_cast<int>(PTN::MAX)] = {
		KEY_TYPE::KEY_Z,
		KEY_TYPE::KEY_SPACE,
		KEY_TYPE::KEY_RIGHT_ARROW,
		KEY_TYPE::KEY_LEFT_ARROW
	};
	
};

