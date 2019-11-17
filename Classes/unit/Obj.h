#pragma once
#include "cocos2d.h"
#include "AnimCtl.h"
#include <list>
#ifdef _DEBUG
#include "debug/_DebugConOut.h"
#include "debug/_DebugGraph.h"
#endif

enum class STATE
{
	IDLE,
	JUMP,
	JUMPING,
	RUN,
	RUNNING,
	FALL,
	FALLING,
	RUN_SHOT,
	MAX
};

struct OPRT;

class Obj:
	public cocos2d::Sprite
{
public:
	Obj();
	~Obj();

	bool init(void) = 0;
	void update(float delta) = 0;

	//get関数
	const float speed(void) { return _speed; };

	//set関数
	void speed(float speed) { _speed = speed; };

protected:
	//キー入力モジュール用
	OPRT* _oprtState;

	//アニメーション用ポインタ変数
	cocos2d::Action* _action;
	float _speed;
	bool _flip;

	std::string _stateName;
	std::string _oldStateName;
};

