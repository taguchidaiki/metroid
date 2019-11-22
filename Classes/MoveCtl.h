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
//矩形の左上座標、右上の座標
using RectData = std::pair<cocos2d::Vec2, cocos2d::Vec2>;

//行動につかうパーツ群
struct ActMojule
{
	std::string stateName;								//この行動を呼び出すための名前
	STATE stateID;										//行動のID
	std::list<STATE> whiteList;							//共存可能なIDリスト
	std::list<STATE> blackList;							//共存不可なIDのリスト

	std::list<MojuleData> actionList;					//この行動が持っているモジュール
	MojuleData runAction;								//この行動のメインモジュール

	std::tuple<PTN, bool, bool> keyData;				//対応しているキー情報
	cocos2d::Vec2 vec;									//移動する方向
	std::map<DIR,RectData> hitRect;						//当たり判定の矩形情報
	bool flip;											//反転用フラグ

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