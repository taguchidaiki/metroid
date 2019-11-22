#pragma once
#include "cocos2d.h"
#include "input/OPRT.h"
#include <map>

#define lpMoveCtl MoveCtl::GetInstance()

enum class DIR
{
	UP,
	DOWN,
	RIGHT,
	LEFT,
	MAX
};

enum class STATE
{
	IDLE,
	JUMP,
	JUMPING,
	MOVE_R,
	MOVE_L,
	RUNNING,
	FALL,
	FALLING,
	RUN_SHOT,
	MAX
};
struct ActMojule;

using MojuleData = std::function<bool(cocos2d::Sprite&, ActMojule &)>;
//��`�̍�����W�A�E��̍��W
using RectData = std::pair<cocos2d::Vec2, cocos2d::Vec2>;

//�s���ɂ����p�[�c�Q
struct ActMojule
{
	std::string stateName;								//���̍s�����Ăяo�����߂̖��O
	STATE stateID;										//�s����ID
	std::list<STATE> whiteList;							//�����\��ID���X�g
	std::list<STATE> blackList;							//�����s��ID�̃��X�g

	std::list<MojuleData> actionList;					//���̍s���������Ă��郂�W���[��
	MojuleData runAction;								//���̍s���̃��C�����W���[��

	std::tuple<PTN, bool, bool> keyData;				//�Ή����Ă���L�[���
	cocos2d::Vec2 vec;									//�ړ��������
	std::map<DIR,RectData> hitRect;						//�����蔻��̋�`���
	bool flip;											//���]�p�t���O

	ActMojule& operator=(const ActMojule& act)
	{
		stateName = act.stateName;
		stateID = act.stateID;
		whiteList = act.whiteList;
		blackList = act.blackList;
		actionList = act.actionList;
		runAction = act.runAction;
		keyData = act.keyData;
		vec = act.vec;
		hitRect = act.hitRect;
		flip = act.flip;
		return (*this);
	}
};

class MoveCtl
{
public:
	static MoveCtl& GetInstance()
	{
		static MoveCtl getInstance;
		return getInstance;
	}

	void AddActMojule(std::string actName, ActMojule& act);
	bool SetActState(cocos2d::Sprite& sp, ActMojule& actData, std::weak_ptr<OPRT> oprt);
	void ActUpdate(cocos2d::Sprite& sp ,ActMojule& actData);

	bool SetActState(cocos2d::Sprite& sp, std::weak_ptr<OPRT> oprt);
	void ActUpdate(cocos2d::Sprite& sp);

	ActMojule GetActData(const std::string& actName);

private:
	MoveCtl() {};
	MoveCtl(MoveCtl&) {};
	MoveCtl& operator=(MoveCtl&) {};
	~MoveCtl() {};

	std::map<std::string, ActMojule> _actList;
};