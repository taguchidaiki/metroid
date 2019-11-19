#pragma once
#include "cocos2d.h"
#include "AnimCtl.h"
#include "move/MoveCtl.h"
#include <list>
#include <memory>
#ifdef _DEBUG
#include "debug/_DebugConOut.h"
#include "debug/_DebugGraph.h"
#endif

struct OPRT;

class Obj:
	public cocos2d::Sprite
{
public:
	Obj();
	virtual ~Obj();

	bool init(void) = 0;
	void update(float delta) = 0;

	//get関数
	const float speed(void) { return _speed; };
	const ActMojule act(void) { return _act; };

	//set関数
	void speed(float speed) { _speed = speed; };
	void act(ActMojule act) { _act = act; };

protected:
	//キー入力モジュール用
	std::unique_ptr<OPRT> _oprtState;
	//OPRT* _oprtState;

	//アニメーション用ポインタ変数
	cocos2d::Action* _action;

	//オブジェクトの移動速度
	float _speed;

	//オブジェクトの移動方向
	cocos2d::Vec2 vec;

	//反転用のフラグ
	bool _flip;

	ActMojule _act;

	std::string _stateName;
	std::string _oldStateName;
};

