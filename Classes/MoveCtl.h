#pragma once
#include "cocos2d.h"
#include "input/OPRT.h"

#define lpMoveCtl MoveCtl::GetInstance()

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
struct ActMojule;

using MojuleData = std::function<bool(cocos2d::Sprite&, ActMojule &)>;

//�s���ɂ����p�[�c�Q
struct ActMojule
{
	STATE stateID;										//�s����ID
	std::list<STATE> whiteList;							//�����\��ID���X�g
	std::list<STATE> blackList;							//�����s��ID�̃��X�g
	std::list<MojuleData> actionList;
	MojuleData runAction;
	std::tuple<PTN, bool, bool> keyData;				//�Ή����Ă���L�[���
	cocos2d::Vec2 vec;									//�ړ��������
	std::pair<cocos2d::Vec2, cocos2d::Vec2> hitRect;	//�����蔻��̋�`���

	ActMojule& operator=(const ActMojule& act)
	{
		stateID = act.stateID;
		whiteList = act.whiteList;
		blackList = act.blackList;
		actionList = act.actionList;
		runAction = act.runAction;
		keyData = act.keyData;
		vec = act.vec;
		hitRect = act.hitRect;
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

private:
	MoveCtl() {};
	MoveCtl(MoveCtl&) {};
	MoveCtl& operator=(MoveCtl&) {};
	~MoveCtl() {};

	std::map<std::string, ActMojule> _actList;
};