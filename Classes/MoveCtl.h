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

//行動につかうパーツ群
struct ActMojule
{
	STATE stateID;										//行動のID
	std::list<STATE> whiteList;							//共存可能なIDリスト
	std::list<STATE> blackList;							//共存不可なIDのリスト
	std::list<MojuleData> actionList;
	MojuleData runAction;
	std::tuple<PTN, bool, bool> keyData;				//対応しているキー情報
	cocos2d::Vec2 vec;									//移動する方向
	std::pair<cocos2d::Vec2, cocos2d::Vec2> hitRect;	//当たり判定の矩形情報

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