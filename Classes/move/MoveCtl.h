#pragma once
#include "cocos2d.h"
#include "unit/Obj.h"

#define lpMoveCtl MoveCtl::GetInstance()

//行動につかうパーツ群
struct ActMojule
{
	STATE stateID;
	std::list<STATE> whiteList;
	std::list<STATE> blackList;
	std::list<std::function<bool(cocos2d::Sprite&, ActMojule&)>> actionList;
	std::function<bool(cocos2d::Sprite&, ActMojule&)> runAction;
};

class MoveCtl
{
public:
	static MoveCtl& GetInstance()
	{
		static MoveCtl getInstance;
		return getInstance;
	}

	void AddActMojule(std::string actName, ActMojule& actMojule);

private:
	MoveCtl() {};
	MoveCtl(MoveCtl&) {};
	MoveCtl& operator=(MoveCtl&) {};
	~MoveCtl() {};

	std::map<std::string, ActMojule> _actMojule;
};