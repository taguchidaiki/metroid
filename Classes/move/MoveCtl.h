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

//行動につかうパーツ群
struct ActMojule
{
	STATE stateID;
	std::list<STATE> whiteList;
	std::list<STATE> blackList;
	std::list<std::function<bool(cocos2d::Sprite&, ActMojule&)>> actionList;
	std::function<bool(cocos2d::Sprite&, ActMojule&)> runAction;
	std::list<std::tuple<KEY, bool, bool>> keyList;
	cocos2d::Vec2 vec;
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
	std::unique_ptr<OPRT> ActUpdate(std::string actName, cocos2d::Sprite& sp, std::unique_ptr<OPRT> oprt);

private:
	MoveCtl() {};
	MoveCtl(MoveCtl&) {};
	MoveCtl& operator=(MoveCtl&) {};
	~MoveCtl() {};

	std::map<std::string, ActMojule> _actMojule;
};