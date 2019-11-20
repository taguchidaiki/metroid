#pragma once
#include "cocos2d.h"
#include "AnimCtl.h"
#include "MoveCtl.h"
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

	//get�֐�
	const float speed(void) { return _speed; };
	const std::list<ActMojule> act(void) { return _act; };

	//set�֐�
	void speed(float speed) { _speed = speed; };
	void act(ActMojule& actData) { _act.emplace_back(actData); };

protected:
	//�L�[���̓��W���[���p
	std::shared_ptr<OPRT> _oprtState;

	//�A�j���[�V�����p�|�C���^�ϐ�
	cocos2d::Action* _action;

	//�I�u�W�F�N�g�̈ړ����x
	float _speed;

	//���]�p�̃t���O
	bool _flip;

	std::list<ActMojule> _act;

	//std::string _stateName;
	//std::string _oldStateName;
};


