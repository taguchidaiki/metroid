#pragma once
#include "MoveCtl.h"
#include "unit/Obj.h"

struct MovFall
{
	bool operator()(cocos2d::Sprite& sp, ActMojule& act);
};