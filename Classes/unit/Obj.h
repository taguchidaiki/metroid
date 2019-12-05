#pragma once
#include "cocos2d.h"
#include "AnimCtl.h"
#include "MoveCtl.h"
#include "EffectCtl.h"
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

	//get�֐�
	const float speed(void) { return _speed; };
	const std::string stateName(void) { return _stateName; }
	
	//set�֐�
	void speed(float speed) { _speed = speed; };
	void stateName(std::string stateName) { _stateName = stateName; }

protected:
	//�L�[���̓��W���[���p
	std::shared_ptr<OPRT> _oprtState;

	
	//�A�j���[�V�����p�|�C���^�ϐ�
	cocos2d::Action* _action;

	//�I�u�W�F�N�g�̈ړ����x
	float _speed;

	//�L�����̍s���p�̖��O
	std::string _stateName;

	////���]�p�̃t���O
	//bool _flip;

	//std::string _oldStateName;
};


