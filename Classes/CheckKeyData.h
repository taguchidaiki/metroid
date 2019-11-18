#pragma once
#include "move/MoveCtl.h"
#include "unit/Obj.h"

struct CheckKey
{
	bool operator()(cocos2d::Sprite& sp, ActMojule& act);
};

