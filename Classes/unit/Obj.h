﻿#pragma once
#include "cocos2d.h"
#include "AnimCtl.h"
#include "MoveCtl.h"
#include "EffectCtl.h"
#include "SoundCtl.h"
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
	const std::string& stateName(void) { return _stateName; }
	const cocos2d::Vec2& gravity(void) { return _gravity; }
	
	//set関数
	void speed(float speed) { _speed = speed; };
	void stateName(std::string stateName) { _stateName = stateName; }
	void gravity(cocos2d::Vec2 gravity) { _gravity = gravity; }

protected:
	//キー入力モジュール用
	std::shared_ptr<OPRT> _oprtState;

	
	//アニメーション用ポインタ変数
	cocos2d::Action* _action;

	//オブジェクトの移動速度
	float _speed;

	//オブジェクトに対する重力
	cocos2d::Vec2 _gravity;

	//キャラの行動用の名前
	std::string _stateName;

	////反転用のフラグ
	bool _flip;

	//std::string _oldStateName;
};


