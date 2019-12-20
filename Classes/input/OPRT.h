#pragma once
#include "cocos2d.h"
#include <map>
#include <array>

#define KEY_TYPE cocos2d::EventKeyboard::KeyCode

enum class PTN
{
	JUMP,
	MOVE_R,
	MOVE_L,
	NON_KEY,
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

	//get関数
	std::array<std::tuple<PTN,bool,bool>, static_cast<int>(PTN::MAX)> key(void) { return _key; };
	
protected:
	//移動方向の情報 _dir[移動方向のベクトル,その方向に移動するかどうか]
	//std::array<std::pair<cocos2d::Vec2,bool>, static_cast<int>(DIR::MAX)> _key;

	//キーの入力情報　_dir[キーの情報] first old情報 second now情報
	std::array<std::tuple<PTN, bool, bool>, static_cast<int>(PTN::MAX)> _key;

	std::array<std::tuple<PTN, bool, bool>, static_cast<int>(PTN::MAX)> _input;

	
};

