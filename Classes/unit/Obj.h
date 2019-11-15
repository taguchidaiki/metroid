#pragma once
#include "cocos2d.h"
#include "AnimCtl.h"
#include "debug/_DebugConOut.h"
#include "debug/_DebugGraph.h"
#include <list>
#include <functional>

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

	//get�֐�

	//set�֐�

protected:
	//�L�[���̓��W���[���p
	OPRT* _oprtState;

	//�A�j���[�V�����p�|�C���^�ϐ�
	cocos2d::Action* _action;
	float _speed;
	bool _flip;

	std::string _stateName;
	std::string _oldStateName;
};

